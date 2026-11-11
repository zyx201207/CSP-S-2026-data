#include <bits/stdc++.h>
using namespace std;
FILE *fin,*fout;
void solve()
{
	long long n,m,sum=0;
	fscanf(fin,"%ld%ld",&n,&m);
	vector<long long> a(n);
	for(int i=0;i<n;++i)
	{
		long long a1;
		fscanf(fin,"%ld",&a1);
		a[i]=a1;
	}
	if(n<m+1)
	{
		fprintf(fout,"%ld\n",sum);
		fclose(fin);
		fclose(fout);
	}
	long long a1=1;
	for(int i=1;i<n;++i)
		if(a[i]-a[i-1]>m)
			a1++;
	vector<long long> s(a1);
	long long j=1,x=0;
	for(int i=0;i<a1;++i)
	{
		for(;j<n;++j)
		{
			if(a[j]-a[j-1]<=m)
				s[i]++;
			if(a[j]-a[j-1]>m)
				break;
		}
		if(s[i]>x)
			x=s[i];
	}
	for(int i=0;i<1;++i)
	{
		if(m==(x/2+1)&&x%2==1)
			sum+=0;
		else if(x-m==2)
			sum+=1;
	}
	fprintf(fout,"%ld\n",sum);
}
int main ()
{
	fin=fopen("migrate.in","r");
	fout=fopen("migrate.out","w");
	
	int c,t;
	fscanf(fin,"%d%d",&c,&t);
	for(int i=0;i<t;++i)
		solve();
	fclose(fin);
	fclose(fout);
	return 0;
}
