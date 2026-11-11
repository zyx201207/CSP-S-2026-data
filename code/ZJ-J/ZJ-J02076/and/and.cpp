#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],s,maxx,c1,c2,c3;
bool flb=0;
bool er(int n)
{
	bool fla=0;
	for(int i=1;i<=32;i++)
	if(n==pow(2,n)-1)fla=1;
	return fla;
}
int main()
{
	bool fla1=0;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];if(a[i]>maxx)maxx=a[i];
		if(a[i]==1)c1++;
		if(a[i]==2)c2++;
		if(a[i]==3)c3++;
		if(a[i]!=i-1)flb=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(er(a[i])==0)fla1=1;
	}
	if(n==m){
		s=a[1];
		for(int i=1;i<=n;i++)s&=a[i];
		cout<<s;
	}else if(m==1){
		long long ma=-1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>ma)ma=a[i];
		}
		cout<<ma;
	}else if(m==2)
	{
		long long ma=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if((a[i]&a[j])>ma&&i!=j){
					ma=(a[i]&a[j]);
				}
			}
		}
		cout<<ma;
	}else if(maxx<4)
	{
		if(m<=c3)cout<<3;
		else if(m<=c3+c2)cout<<2;
		else cout<<1;
	}else if(m==n-1)
	{
		long long ma=-1;
		for(int i=1;i<=n;i++)
		{
			if(i==1)s=a[2];
			else s=a[1];
			for(int j=1;j<=n;j++)
			{
				if(i!=j)s&=a[j];
			}
			if(s>ma)ma=s;
		}
		cout<<ma;
	}else if(fla1==0)
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}else if(flb==0){
		cout<<n-m-1;
	}else
	{
		long long ma=-1,ki=0,kj=0;
		while(m>1)
		{
			for(int i=1;i<n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(a[i]>=0&&a[j]>=0)
					{
						if((a[i]&a[j])>ma&&i!=j){
							ma=(a[i]&a[j]);
							ki=i,kj=j;
						}
					}
				}
			}
			a[ki]=ma;
			a[kj]=-1;
			m--;
			ma=-1;
		}
		cout<<a[ki];
	}
	return 0;
}//B
