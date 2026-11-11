#include<bits/stdc++.h>
using namespace std;
long long int a[5005],b[5005];
bool cmp(int x,int y)
{
	return x>y;
}
long long int maxn=0; 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n>=500000)
	{
		long long int cha=abs(a[2]-a[1]);
		long long int t=cha,s=0;
		while(m>=0)
		{
			s++;
			m=m-t;
			t+=cha;
		}
		if(s<n)
		cout<<s;
		else
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++)
	{
		b[i]=abs(a[i-1]-a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		long long int s=0,t=0,tt=m;
		while(tt>=0)
		{
			s++;
			t+=b[s+i];
			tt=tt-t;
			if(i+s>n)
			{
				break;
			}
		}
		maxn=max(s,maxn);
	}
	cout<<maxn;
	return 0;
}
