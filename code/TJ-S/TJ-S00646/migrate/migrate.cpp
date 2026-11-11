#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
const int N=1e5;
const int INF=1e9;
int c,T=1;
int n;
ll d,x[N];
int f[N],lst[N],fst[N];
int dis[N],cnt[N];
queue<int>q;
ll ans;
void BFS(int s)
{
	q.push(s);int u;
	while(q.size())
	{
		u=q.front();q.pop();
		for(int i=fst[u];i<=lst[u];i++)
		{
			if(i==u)continue;
			if(dis[i]>dis[u]+1)
			{
				dis[i]=dis[u]+1;cnt[i]=cnt[u];
			}
			else if(dis[i]==dis[u]+1)
			{
				cnt[i]+=cnt[u];
			}
			if(f[i])continue;
			f[i]=u;
			q.push(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]==2)
		{
//			cout<<s<<' '<<i<<'\n';
			ans++;
		}
	}
}
void solve()
{
	cin>>n>>d;ans=0;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int L=1,R=0;L<=n&&R<=n;L++)
	{
		while(R<n&&x[R+1]-x[L]<=d)R++;
		lst[L]=R;
	}
	for(int L=n+1,R=n;L>0&&R>0;R--)
	{
		while(L>1&&x[R]-x[L-1]<=d)L--;
		fst[R]=L;
	}
	for(int u=1;u<=n;u++)
	{
		for(int i=1;i<=n;i++)
		{
			f[i]=0;dis[i]=INF;cnt[i]=0;
		}
		dis[u]=0;cnt[u]=1;f[u]=u;
		BFS(u);
	}
	cout<<ans/2<<'\n';
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
//in
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
//out
/*
1
2
*/

//in
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
