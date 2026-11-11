#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],t[300005],qz,xb;
bool f=1;
int b[500005],wz[300005],ans[300005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<qz) f=0;
		t[a[i]]++;
		qz=a[i];
	}
	if(f==1)
	{
		for(int i=1;i<=m;i++)
		{
			t[i]=t[i-1]+t[i];
			cout<<t[i]<<' ';
		}	
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			memset(wz,0,sizeof(wz));
			memset(b,0,sizeof(b));
			xb=0;
			for(int j=i;j<=n;j++)
			{
				if(wz[a[j]]) 
				{
					int wxb=wz[a[j]];
					for(int k=wxb;k<=xb;k++)
						wz[b[k]]=0,b[k]=0;
					xb=wxb;
					b[xb]=a[j];
					wz[a[j]]=xb;
				}
				else
					b[++xb]=a[j],wz[a[j]]=xb;
				
			}
			for(int j=1;j<=xb;j++)
				ans[b[j]]++;
		}
		for(int i=1;i<=m;i++)
			cout<<ans[i]<<' ';
	}
}