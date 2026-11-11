#include<bits/stdc++.h>
using namespace std;
long long a[500010]={0},b[500010]={0};
bool f(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	long long n,p;
	cin>>n>>p;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,f);
	b[0]=0;
	for(long long i=1;i<n;i++) {b[i]=a[i-1]-a[i];}//hahahaha
	long long tc=0;
	long long zz=0;
	long long z=2;
	long long q=p;
	long long r=0;
	for(long long i=0;i<n;i++)
	{
		if(q<p) q+=b[i]*(z-1);
		if(i>r)
		{
			r++;
			z=2;	
		} 
		z--;
		if(tc>0) tc-=b[i];
		while(q>=0)//zhongdianyi
		{
			if(!(r+1<n)) break;
			if(q-(tc+b[r+1])>=0)
			{
				r++;
			    q=q-(tc+b[r]);
			    z++;
			    tc+=b[r];
			}
			else break;
    	}
    	zz=max(zz,z);
	}
	cout<<zz;
	fclose(stdin);
	fclose(stdout);
} 
