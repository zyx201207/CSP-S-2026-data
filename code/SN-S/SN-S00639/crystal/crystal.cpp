#include <bits/stdc++.h>
using namespace std;
FILE *fin,*fout;
struct crystal
{long long cz;};
int main ()
{

	fin=fopen("crystal.in","r");
	fout=fopen("crystal.out","w");
	
	long long n,m,sum=0;
	fscanf(fin,"%ld%ld",&n,&m);
	vector<long long> a(n);
	vector<crystal> crt(n-1);
	for(int i=0;i<n;++i)
	{
		long long a1;
		fscanf(fin,"%ld",&a1);
		a[i]=a1;
	}
	sort(a.begin(),a.end());
	long long a12;
	for(int i=0;i<n-1;++i)
	{
		crt[i].cz=a[i]-a[i+1];
		if(crt[i].cz!=0)
		a12++;
	}
	if(a12==0)
	{
		fprintf(fout,"%ld",m);
		fclose(fin);
		fclose(fout);
		return 0;
	}
	int a123=0;
	for(int i=n-2;i>=2;--i)
	{
		if(crt[i].cz-crt[i-1].cz!=crt[i-1].cz-crt[i-2].cz)
			a123=1;
	}
	if(a123==0)
	{
		m/=crt[0].cz;
		m*=-1;
		sum=(sqrt(1+8*m)+1)/2;
		fprintf(fout,"%ld",sum);
		fclose(fin);
		fclose(fout);
		return 0;
	}
	
	fprintf(fout,"%ld",sum);
	
	fclose(fin);
	fclose(fout);
	return 0;
}
