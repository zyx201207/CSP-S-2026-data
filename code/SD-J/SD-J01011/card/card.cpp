#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[300005];
int c[500005];
int d[500005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool f=1,g=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<a[i-1]) f=0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>a[i-1]) g=0;
	}
	if(f||g)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[i+1])
			{
				ans[a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		memset(d,0,sizeof(d));
		d[i]=1;
		c[i-1]=0;
		map<int,int> mp;
		for(int j=i;j<=n;j++)
		{
			if(mp.count(a[j]))
			{
				d[mp[a[j]]]--;
				d[j]++;
			}
			mp[a[j]]=j;
			//for(int z=i;z<=n;z++) cout<<d[z]<<" ";
			//cout<<endl;
		}
		for(int j=i;j<=n;j++)
		{
			c[j]=c[j-1]+d[j];
			if(c[j]) ans[a[j]]++;
			//cout<<c[j]<<"   ";
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
/*
4 3
1 2 1 3

3 1 4*/
/*
10 3
3 1 2 1 3 2 3 1 2 1

10 3 3*/
