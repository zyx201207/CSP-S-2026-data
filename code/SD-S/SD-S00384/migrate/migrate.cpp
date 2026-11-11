#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int c,T;
int n,d;
int a[2000005];
int vis[305][305];
int mi;
void getmi(int x,int y,int nw)
{
	int i;
	if(vis[x][y])
	{
		mi = min(mi,vis[x][y]);
		return;
	}
	if(x==y)
	{
		mi = min(mi,nw);
		return;
	}

	for(i=x+1;i<=y;i++)
	{
		if(a[i]-a[x]<=d)
			getmi(i,y,nw+1);
	}
	return;
}
int cnt;
void get(int x,int y,int nw,int need)
{
	if(nw>mi)
		return;
	if(cnt>=3)
		return;
	int i;
	if(vis[x][y])
	{
		mi = min(mi,vis[x][y]);
		return;
	}
	if(x==y)
	{
//		cout<<nw<<' '<<need<<endl;
//		mi = min(mi,nw);
		if(nw==need)
		{
			cnt++;
			if(cnt>=3)
				return;
//			cout<<cnt<<endl;
		}
		return;
	}

	for(i=x+1;i<=y;i++)
	{
		if(a[i]-a[x]<=d)
			get(i,y,nw+1,need);
	}
	return;
}
signed main()
{
	fast;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		int i;
		for(i=1;i<=n;i++)
			cin>>a[i];
		memset(vis,0,sizeof vis);
		int j;
		int ans = 0;
		for(i=1;i<n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				mi = INT_MAX;
				getmi(i,j,1);

				cnt = 0;
				get(i,j,1,mi);

				if(cnt==2)
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}



/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
