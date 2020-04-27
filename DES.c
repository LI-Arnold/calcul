#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int InversePermutation[] = 
{
	  58, 50, 42, 34, 26, 18, 10, 2,
	  60, 52, 44, 36, 28, 20, 12, 4,
	  62, 54, 46, 38, 30, 22, 14, 6,
	  64, 56, 48, 40, 32, 24, 16, 8,
	  57, 49, 41, 33, 25, 17,  9, 1,
	  59, 51, 43, 35, 27, 19, 11, 3,
	  61, 53, 45, 37, 29, 21, 13, 5,
	  63, 55, 47, 39, 31, 23, 15, 7
};

int Expension[] = 
{
	  32,  1,  2,  3,  4,  5,
	   4,  5,  6,  7,  8,  9,
	   8,  9, 10, 11, 12, 13,
	  12, 13, 14, 15, 16, 17,
	  16, 17, 18, 19, 20, 21,
	  20, 21, 22, 23, 24, 25,
	  24, 25, 26, 27, 28, 29,
	  28, 29, 30, 31, 32,  1
};

int PC1inv[] = {
	8,	16,	24,	56,	52,	44,
	36,	0,	7,	15,	23,	55,
	51,	43,	35,	0,	6,	14,
	22,	54,	50,	42,	34,	0,
	5,	13,	21,	53,	49,	41,
	33,	0,	4,	12,	20,	28,
	48,	40,	32,	0,	3,	11,
	19,	27,	47,	39,	31,	0,
	2,	10,	18,	26,	46,	38,
	30,	0,	1,	9,	17,	25,
	45,	37,	29,	0
};

int PC2inv[] = {
	5,	24,	7,	16,	6,	10,
	20,	18,	0,	12,	3,	15,
	23,	1,	9,	19,	2,	0,
	14,	22,	11,	0,	13,	4,
	0,	17,	21,	8,	47,	31,
	27,	48,	35,	41,	0,	46,
	28,	0,	39,	32,	25,	44,
	0,	37,	34,	43,	29,	36,
	38,	45,	33,	26,	42,	0,
	30,	 40
};

int PermutationInverse[] = {
	9,	17,	23,	31,
	13,	28,	2,	18,
	24,	16,	30,	6,
	26,	20,	10,	1,
	8,	14,	25,	3,
	4,	29,	11,	19,
	32,	12,	22,	7,
	5,	27,	15,	21
};

int Sbox[][4][16] = {
	{
		{14,	4,	13,	1,	2,	15,	11,	8,	3,	10,	6,	12,	5,	9,	0,	7},
		{0,	15,	7,	4,	14,	2,	13,	1,	10,	6,	12,	11,	9,	5,	3,	8},
		{4,	1,	14,	8,	13,	6,	2,	11,	15,	12,	9,	7,	3,	10,	5,	0},
		{15,	12,	8,	2,	4,	9,	1,	7,	5,	11,	3,	14,	10,	0,	6,	13}
	},
	{
		{15,	1,	8,	14,	6,	11,	3,	4,	9,	7,	2,	13,	12,	0,	5,	10},
		{3,	13,	4,	7,	15,	2,	8,	14,	12,	0,	1,	10,	6,	9,	11,	5},
		{0,	14,	7,	11,	10,	4,	13,	1,	5,	8,	12,	6,	9,	3,	2,	15},
		{13,	8,	10,	1,	3,	15,	4,	2,	11,	6,	7,	12,	0,	5,	14,	9}
	},
	{
		{10,	0,	9,	14,	6,	3,	15,	5,	1,	13,	12,	7,	11,	4,	2,	8},
		{13,	7,	0,	9,	3,	4,	6,	10,	2,	8,	5,	14,	12,	11,	15,	1},
		{13,	6,	4,	9,	8,	15,	3,	0,	11,	1,	2,	12,	5,	10,	14,	7},
		{1,	10,	13,	0,	6,	9,	8,	7,	4,	15,	14,	3,	11,	5,	2,	12}
	},
	{
		{7,	13,	14,	3,	0,	6,	9,	10,	1,	2,	8,	5,	11,	12,	4,	15},
		{13,	8,	11,	5,	6,	15,	0,	3,	4,	7,	2,	12,	1,	10,	14,	9},
		{10,	6,	9,	0,	12,	11,	7,	13,	15,	1,	3,	14,	5,	2,	8,	4},
		{3,	15,	0,	6,	10,	1,	13,	8,	9,	4,	5,	11,	12,	7,	2,	14}
	},
	{
		{2,	12,	4,	1,	7,	10,	11,	6,	8,	5,	3,	15,	13,	0,	14,	9},
		{14,	11,	2,	12,	4,	7,	13,	1,	5,	0,	15,	10,	3,	9,	8,	6},
		{4,	2,	1,	11,	10,	13,	7,	8,	15,	9,	12,	5,	6,	3,	0,	14},
		{11,	8,	12,	7,	1,	14,	2,	13,	6,	15,	0,	9,	10,	4,	5,	3}
	},
	{
		{12,	1,	10,	15,	9,	2,	6,	8,	0,	13,	3,	4,	14,	7,	5,	11},
		{10,	15,	4,	2,	7,	12,	9,	5,	6,	1,	13,	14,	0,	11,	3,	8},
		{9,	14,	15,	5,	2,	8,	12,	3,	7,	0,	4,	10,	1,	13,	11,	6},
		{4,	3,	2,	12,	9,	5,	15,	10,	11,	14,	1,	7,	6,	0,	8,	13}
	},
	{
		{4,	11,	2,	14,	15,	0,	8,	13,	3,	12,	9,	7,	5,	10,	6,	1},
		{13,	0,	11,	7,	4,	9,	1,	10,	14,	3,	5,	12,	2,	15,	8,	6},
		{1,	4,	11,	13,	12,	3,	7,	14,	10,	15,	6,	8,	0,	5,	9,	2},
		{6,	11,	13,	8,	1,	4,	10,	7,	9,	5,	0,	15,	14,	2,	3,	12}
	},
	{
		{13,	2,	8,	4,	6,	15,	11,	1,	10,	9,	3,	14,	5,	0,	12,	7},
		{1,	15,	13,	8,	10,	3,	7,	4,	12,	5,	6,	11,	0,	14,	9,	2},
		{7,	11,	4,	1,	9,	12,	14,	2,	0,	6,	10,	13,	15,	3,	5,	8},
		{2,	1,	14,	7,	4,	10,	8,	13,	15,	12,	9,	0,	3,	5,	6,	11}
	}
};

void afficher_en_bits(long k, int n) {
	for(int i = n - 1; i >= 0; i--) {
		printf("%ld", (k >> i) & 1); 
	}
	printf("\n");
}

long permutaionIP(long y){
	long res = 0x0000000000000000L;
	long p = 0x0000000000000001L;
	long tmp;
	
	for(int i = 0; i < 64; i++) {
		tmp = p << (64 - InversePermutation[i]);
		tmp = y & tmp; 
		tmp = tmp >> ((64 - InversePermutation[i])) & 1;
		tmp = tmp << (64 - (i + 1));
		res = res | tmp;
		}
	return res;
}

long PermutaionInvP(long cle){
	long res = 0x0000000000000000L;
	long p = 0x0000000000000001L;
	long tmp;
	
	for(int i = 0; i < 32; i++) {
		tmp = p << (32 - PermutationInverse[i]);
		tmp = cle & tmp;
		tmp = tmp >> ((32 - PermutationInverse[i])) & 1;
		tmp = tmp << (32 - (i + 1));
		res = res | tmp;
		}
	return res;

}

long PC1InvF(long cle) {
	long res = 0x0000000000000000L;
	long p = 0x0000000000000001L;
	long tmp;
	
	for(int i = 0; i < 64 ; i++) {
		if(PC1inv[i]) {
			tmp = p << (56 - PC1inv[i]);
			tmp = cle & tmp;
			tmp = tmp >> (56 - PC1inv[i]) & 1;
			tmp = tmp << (64 - (i + 1));
			res = res | tmp;
		}
	}
	
	return res;
}

long PC2InvF(long cle) {
	long res = 0x0000000000000000L;
	long p = 0x0000000000000001L;
	long tmp;
	
	for(int i = 0; i < 56 ; i++) {
		if(PC2inv[i]) {
			tmp = p << (48 - PC2inv[i]);
			tmp = cle & tmp;
			tmp = tmp >> (48 - PC2inv[i]) & 1;
			tmp = tmp << (56 - (i + 1));
			res = res | tmp;
		}
	}
	
	return res;
}


void SboxErrones(long cle ,int t[]){
	int tmp;
	
	for(int i = 0; i < 8; i++) {
			tmp = (cle >> (48 - (6 * (i + 1)))) & 0x3F;
			if(tmp!=0)
				t[i]=1;
	}
}

long Expansion(long cle){
	long res = 0x0000000000000000L;
	long p = 0x0000000000000001L;
	long tmp;
	
	for(int i = 0; i < 48; i++) {
		tmp = p << (32 - Expension[i]);
		tmp = cle & tmp;
		tmp = tmp >> ((32 - Expension[i])) & 1;
		tmp = tmp << (48 - (i + 1));
		res = res | tmp;	
	}
	
return res;
}

long s_boxFanc(long cle ,int j){
	int tmp2 = 0x00000001;
	int tmp = (cle >> 5) & 0x00000001;
	
	tmp2 = cle & tmp2;
	tmp = (tmp << 1) | tmp2;

	tmp2 = (cle >> 1) & 0x0000000F;

	return Sbox[j][tmp][tmp2];
	
	}

long chercher_k16(long juste,long faute[]){
	int v=0;
	long valeurPossiblePerSbox[8][15] = {{-1}, {-1}, {-1}, {-1},{-1}, {-1}, {-1}, {-1}};
	long R16,L16,FL16,FR16,e,A,c,Fc,test1, test2, test3;


	c = permutaionIP(juste);

	L16 = (c >> 32) & 0xFFFFFFFFL;
	R16 = c  & 0xFFFFFFFFL;

	for(int i = 0; i < 32; i++) {
		
		int SboxErroner[8]={-1, -1, -1, -1,-1, -1, -1, -1};
			
		Fc = permutaionIP(faute[i]);
		
		FL16 = (Fc >> 32) & 0xFFFFFFFFL;
		FR16 = Fc & 0xFFFFFFFFL;
			
		A = L16 ^ FL16;
		e = (R16 ^ FR16) & 0xFFFFFFFFL;
		A = PermutaionInvP(A);
		e = Expansion(e);
		SboxErrones(e,SboxErroner);
	
		for(int j = 0;j < 8; j ++){
			v=0;
			if(SboxErroner[j] != -1){
			long tmp = A >> (32 - (4 * (j + 1))) & 0x0000000F;
			long ExpR16 = Expansion(R16);
			long d = ExpR16 ^ e;
			d = d >> (48 - (6 * (j + 1))) & 0x3F;
			ExpR16 = ExpR16 >> (48 - (6 * (j + 1))) & 0x3F;
		if(valeurPossiblePerSbox[j][0]==-1){
			for(long k = 0;k < 64; k ++){
				test1 = k ^ ExpR16;
				test2 = k ^ d;
				test3 = s_boxFanc(test1,j) ^ s_boxFanc(test2,j);
				if(tmp == test3){
						valeurPossiblePerSbox[j][v] = k;
						v++;
					}
			}	
		}else{
			for(int k = 0;k < 15; k ++){
				if(valeurPossiblePerSbox[j][k]!=0){
						test1 = valeurPossiblePerSbox[j][k] ^ ExpR16;
						test2 = valeurPossiblePerSbox[j][k] ^ d;	
						test3 = s_boxFanc(test1,j) ^ s_boxFanc(test2,j);
					if(tmp != test3){
							valeurPossiblePerSbox[j][k] = -5 ;
					}
				}
			}
		}
	  }
 	 }	

	}
		for(int l = 0;l < 8; l ++){
			for(int n = 0;n < 15; n ++){

				if(valeurPossiblePerSbox[l][n]!=0 && valeurPossiblePerSbox[l][n]!=-5 ){
					valeurPossiblePerSbox[l][0] = valeurPossiblePerSbox[l][n];
				}
			}
		}
	long k16_finale =0x000000000000L;
	
	for(int l = 0;l < 8; l ++){
		long a=valeurPossiblePerSbox[l][0] << (48 -(6 * (l+1)));
		k16_finale = k16_finale | a;
	}
	return k16_finale;
}



long bits_pariter(long K) {
	long res = K;
	long tmp, pariter;
	
	for(int i = 0; i < 8; i++) {
		pariter = 0;
		for(int j = 0; j < 8; j++) {
			if(j != 7) {
				tmp = 0x1L << (((7 - i) * 8) + (7 - j));
				tmp = K & tmp;
				pariter = tmp ? pariter ^ 1 : pariter ^ 0;
			}
			else {
				tmp = !pariter;
				res |= tmp << ((7 - i) * 8);
			}
		}
	}
	return res;
}

long chercher_k(long x,long chiffre,long clair){
	long pos[] = {14, 15, 19, 20, 51, 54, 58, 60};
	long res = 0x0L;
	long tmp = 0x00L;
	long k48 = PC1InvF(PC2InvF(x));
	long k;
	while(tmp < 256){
		for(int j = 0; j < 8; j++) {
			res |= ((tmp >> j) & 1) << (64 - pos[j]);
		}
		k= k48 | res;
		++tmp;
		res=0x0L;
		k=bits_pariter(k);	
			return k;
	}
}


int main(){
long MsgClair = 0x0E52047352A19B64L;
long MsgChiffre = 0xF2093D000B71C200L;
long faute[] = {
0xF01C3D440B70C210L, 
0xF20B3D040B70C200L,
0xF2193F440B71C200L,
0xF3593D060B70C200L,
0xF35939400971C200L,
0xF2493D001B73C200L,
0xF30939000B71C000L,
0xF3493D014B61C202L,
0xFB4939004B65C200L,
0xF2013D000B65C200L,
0xF20935010B61C200L,
0xB2092D090B25C200L,
0xF2092D010361C201L,
0xF2092D000B39C201L,
0xB2093D000B71CA01L,
0xB2092D000F71C249L,
0xD2092D000B31D240L,
0xF2293D000B71D340L,
0xF2091D000F71C340L,
0xE6097C200F71D340L,
0xF6097C002B71D240L, 
0xF6093C000B51C200L, 
0xE6097C000B71E200L, 
0xE2097D100B718620L,
0x62093C100A71C200L,
0xF2893D100A71C600L,
0xF209BD000A718600L,
0xF2083D900B718210L,
0xF20D3D108A71C614L, 
0xF20C3D000BF1C210L, 
0xF20C3D000B714204L,
0xF20C3D400B70C294L
};


long k16=chercher_k16(MsgChiffre,faute);
afficher_en_bits(k16,48);
printf("k16 = %lx \n",k16);
long k=chercher_k(k16,MsgChiffre,MsgClair);
afficher_en_bits(k,64);
printf("k = %lx \n",k);

}
