#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=100005;
int n,m,a[5*N],c[2*N],g=1e5,res;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>a[1]>>a[2];
	c[a[1]+g]++,c[a[2]+g]++;
	int y=a[2]-a[1];
	bool b=true;
	int minn,maxn;
	minn=min(a[1],a[2]),maxn=max(a[1],a[2]);
	for(int i=3;i<=n;i++)
	{
		int x=1e5;
		cin>>a[i];
		x+=a[i];
		c[x]++;
		if(a[i]-a[i-1]!=y)
			b=false;
		minn=min(a[i],minn);
		maxn=max(a[i],maxn);
	}
	if(b)
	{
		int i=1;
		for(;m>0;i++)
		{
			m-=i*y;
		}
		cout<<i-1;
		return 0;
	}
	for(int i=1;i<=maxn-minn+1;i++)
	{
		for(int j=minn+g;j<=maxn+g-i+1;j++)
		{
			int mx=m,ans=c[j+i-1];
			for(int k=j+i-2,s=1;k>=j;k--,s++)
			{
				if(mx<=0)
					break;
				int js=min(mx/s,c[k]);
				mx-=js;
				ans+=js;
			}
			res=max(res,ans);
		}
	}
	cout<<res;
	return 0;
}
