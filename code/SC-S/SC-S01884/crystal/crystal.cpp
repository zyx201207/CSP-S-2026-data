#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
long long a[500005];
long long s[500005];
long long st[500005][20];
int n;
long long m;
long long ask(int l,int r)
{
	int k=log2(r-l+1);
	//cout<<l<<" "<<r<<" "<<max(st[l][k],st[r-(1<<k)+1][k])<<endl;
	return max(st[l][k],st[r-(1<<k)+1][k]);
}
bool check(int x)
{
	for(int i=x;i<=n;i++)
	{
		if(x*ask(i-x+1,i)-s[i]+s[i-x]<=m)return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=0;(1<<i)<=n;i++)
	{
		for(int j=1;j+(1<<i)-1<=n;j++)
		{
			if(i==0)
				st[j][i]=a[j];
			else
				st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		}
	}
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
}