#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
bool dp[200000];
int main()
{
	FILE *fin,*fout;
	fin=fopen("and.in","rb");
	fout=fopen("and.out","wb");
	
	
	int n,m,a[200000],ss=-1,t;
	
	fscanf(fin,"%d%d",&n,&m);
	for(int i=0;i<n;i++){
		fscanf(fin,"%d",&a[i]);
		if(ss<a[i]){
			ss=a[i];
			t=i;
		}
	}
	
	if(n==1){
		fprintf(fout,"%d",a[0]);
		return 0;
	}
	if(m==1){
		fprintf(fout,"%d",ss);
		return 0;
	}
	if(m==n){
		int ts=a[0];
		for(int i=1;i<n;i++)ts&=a[i];
		fprintf(fout,"%d",ts);
		return 0;
	}
	if(m==2){
		int ts=a[0]&a[1];
		for(int i=0;i<n;i++)
			for(int j=0;j<i;j++)
				ts=ts>=a[i]&a[j]?ts:a[i]&a[j];
		fprintf(fout,"%d",ts);
		return 0;
	}
	int sum=ss;dp[t]=true;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			int tt=-1;
			if(sum&a[j]>tt&&!dp[j]){
				t=j;
				tt=sum&a[j];
			}
			sum=tt;
			dp[j]=true;
		}
	}
	
	 
	fprintf(fout,"%d",sum);
	
	
	//fscanf(fin,"%d",&a);
	//fprintf(fout,"%d",a+1);
	return 0;
} 
