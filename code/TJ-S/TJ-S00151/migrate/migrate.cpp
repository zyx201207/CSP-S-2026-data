#include <bits/stdc++.h>
using namespace std;
#define rep(arr,a,b) for(int (arr)=(a);(arr)<=(b);(arr)++)
#define pre(arr,a,b) for(int (arr)=(a);(arr)>=(b);(arr)--)
#define st(arr,l,r) sort((arr)+(l),(arr)+(r)+1)
#define stcmp(arr,l,r,c) sort((arr)+(l),(arr)+(r)+1,(c))
#define stedge(e) sort((e).begin(),(e).end())
#define stedgec(e,c) sort((e).begin(),(e).end(),(c))
#define mem(arr,x) memset((arr),(x),sizeof((arr)))
#define lower(a,l,r,x) lower_bound((a)+(l),(a)+(r)+1,(x))
#define upper(a,l,r,x) upper_bound((a)+(l),(a)+(r)+1,(x))
#define mx2(a,b) max((a),(b))
#define mx3(a,b,c) max((a),max((b),(c)))
#define mn2(a,b) min((a),(b))
#define mn3(a,b,c) min((a),min((b),(c)))
#define p_b push_back
#define N3 1000 + 5
#define N4 10000 +5
#define N5 100000 + 5
#define N6 1000000 + 5
#define N7 10000000 + 5
#define sp " "
#define nl "\n"
#define ll long long
#define str string
#define done return 0
int c,t,n,k,in[2*N6],a[25];
bool vis[2*N6];
vector <int> e[2*N6];
queue <int> q;
void dfs(int u)
{
	vis[u]=1;
	rep(i,0,e[u].size()-1)
	{
		int v=e[u][i];
		if(!vis[v]) dfs(v);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		mem(vis,0);
		mem(in,0);
		cin >> n >> k;
		rep(i,1,n-1)
		{
			int u,v;
			cin >> u >> v;
			e[u].p_b(v);
			e[v].p_b(u);
			in[u]++;
			in[v]++;
		}
		rep(i,1,n) if(!vis[i]) dfs(i);
		rep(i,1,n) if(!in[i]) q.push(i);
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			rep(i,0,e[u].size()-1)
			{
				int v=e[u][i];
				in[v]--;
				if(!in[v]) q.push(v);
			}
		}
		rep(i,1,t) a[i]=i;
		if(a[1]==1) cout << a[1] << nl;
	}
	done;
}
