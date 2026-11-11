#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	FILE *fin,*fout;
	fin=fopen("travel.in","rb");
	fout=fopen("travel.out","wb");
	
	
	int cxR,cxX;
	char zwR[4],zwX[4];
	
	fscanf(fin,"%d",&cxR);
	fscanf(fin,"%s",zwR);
	fscanf(fin,"%d",&cxX);
	fscanf(fin,"%s",zwX);
	//fprintf(fout,"%d ",cxR);
	//for(int i=0;i<3;i++)
	//	fprintf(fout,"%c ",zwR[i]);
	
	int a=0,b=0,c=0,d=0;
	if(cxR==cxX){
		a=1;
		if(zwR[0]==zwX[0]&&zwR[1]==zwX[1]){
			b=1;
			if(zwR[2]=='F')zwR[2]='E';
			if(zwX[2]=='F')zwX[2]='E';
			if(('A'<=zwR[2]&&zwR[2]<='C'&&'A'<=zwX[2]&&zwX[2]<='C')||('D'<=zwR[2]&&zwR[2]<='E'&&'D'<=zwX[2]&&zwX[2]<='E')){
				c=1;
				if(zwR[2]-zwX[2]==1||zwR[2]-zwX[2]==-1)d=1;
			}
		}
	}
	fprintf(fout,"%d%d%d%d",a,b,c,d);
	
	//fscanf(fin,"%d",&a);
	//fprintf(fout,"%d",a+1);
	return 0;
} 
