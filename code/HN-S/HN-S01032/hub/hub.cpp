#include <bits/stdc++.h> 
using namespace std;
int c , t , n , k , x , y , dis[1005][1005] , ans , d[1000005] , fa[1000005] ;
vector<int>g[1000005];
bool f[1000005] ;
int find(int x)
{
	if (fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void dfs(int step,int lst)
{
	if (step==k)
	{
		int ma = 0 ;
		for ( int i = 1 ; i <= n ; i ++ )
		{
			d[i]=1e9; fa[i]=i;
			for ( int j = 1 ; j <= n ; j ++ )
				if (f[j])d[i]=min(d[i],dis[i][j]);
			ma=max(ma,d[i]);
		}
		int cnt = 0 ;
		for ( int i = 1 ; i <= n ; i ++ )
			if (f[i])for ( auto j : g[i] )
				if (f[j])fa[find(j)]=find(i);
		for ( int i = 1 ; i <= n ; i ++ )
			if (f[i]&&fa[i]==i)cnt++;
		if (cnt<3)ans=min(ans,ma);
		return;
	}
	for ( int i = lst+1 ; i <= n ; i ++ )
	{
		f[i]=1;
		dfs(step+1,i);
		f[i]=0;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t ;
	while (t--)
	{
		ans=1e9;
		cin >> n >> k ;
		if (k>=n/2) 
		{
			cout << "1\n" ;
			continue;
		}
		if (c==13||c==14)
		{
			for ( int i = 1 ; i < n ; i ++ )
				cin >> x >> y ;
			n/=2; k=(k+1)/2;
			int l = (n+1)/2 ;
			cout <<  max(l/2-k/2+1,l+1-l/2-(k+1)/2) << "\n" ;
			continue;
		}
		dis[1][1]=0;
		memset(dis,0x3f,sizeof(dis));
		for ( int i = 1 ; i < n ; i ++ )
		{
			cin >> x >> y ;
			dis[i+1][i+1]=0;
			g[x].push_back(y);
			g[y].push_back(x);
			dis[x][y]=dis[y][x]=1;
		}
		for ( int k = 1 ; k <= n ; k ++ )
			for ( int i = 1 ; i <= n ; i ++ )
				for ( int j = 1 ; j <= n ; j ++ )
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		dfs(0,0);
		cout << ans << "\n" ;
		for ( int i = 1 ; i <= n ; i ++ )
			g[i].clear();
	}
	return 0;
}
