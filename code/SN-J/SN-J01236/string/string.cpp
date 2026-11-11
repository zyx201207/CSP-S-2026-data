#include<stdio.h>
#include<iostream>
#include<math.h>
//#define fin stdin
//#define fout stdout
using namespace std;
int main()
{
	FILE *fin,*fout;
	fin=fopen("string.in","rb");
	fout=fopen("string.out","wb");
	
	
	long n,a[200000],c[200000],t;
	
	fscanf(fin,"%d",&n);
	if(n==1)
	{
		fprintf(fout,"0");
		return 0;
	}
	for(int i=0;i<n;i++){
		fscanf(fin,"%d%s",&a[i],&t);
		c[i]=t;
	}
	long cha,ans=0,i=0,j=n-1,k1=a[0],k2=0;
	while(i!=j)
	{
		if(k1>k2)
		{
			//fprintf(fout,"c%d ",min(k1,k2+a[j])-max(k1-a[i],k2));
			//fprintf(fout,"i%d-%d j%d-%d ",i,c[i],j,c[j]);
			if(c[j]!=c[i])ans+=min(k1,k2+a[j])-max(k1-a[i],k2)>0?min(k1,k2+a[j])-max(k1-a[i],k2):-min(k1,k2+a[j])+max(k1-a[i],k2);
			k2+=a[j--];
			//fprintf(fout,"a%d \n",ans);
		}
		else
		{
			//fprintf(fout,"c%d ",min(k1+a[i],k2)-max(k1,k2-a[j]));
			//fprintf(fout,"i%d-%d j%d-%d ",i,c[i],j,c[j]);
			if(c[j]!=c[i])ans+=min(k1+a[i],k2)-max(k1,k2-a[j])>0?min(k1+a[i],k2)-max(k1,k2-a[j]):-min(k1+a[i],k2)+max(k1,k2-a[j]);
			k1+=a[i++];
			//fprintf(fout,"a%d \n",ans);
		}
	}
	fprintf(fout,"%d",ans);
	
	
	
	//fscanf(fin,"%d",&a);
	//fprintf(fout,"%d",a+1);
	return 0;
} 
