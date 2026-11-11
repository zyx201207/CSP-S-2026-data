#include<bits/stdc++.h>
using namespace std;
/*
1.这个点没被记录过 
2.新路程和原路程一样 
*/ 
#define ll long long
const int maxn=2e6+5;//全部 
const int maxn1=5005;//O(n2)写法
const ll INF=1e18; 
vector<int>g1[maxn1];
ll x[maxn1]; 
int n;
ll d;
ll dis[maxn1];//记录这个点与s的距离 
ll ans;
int num[maxn1];
void bfs(int s)
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=INF;
		num[i]=0;
	}
	queue<int> q;
	q.push(s);
	dis[s]=0;
	while(q.size())
	{
		int u=q.front();
		q.pop(); 
//		cout<<u<<' ';
		for(int i=0;i<g1[u].size();i++)
		{
			int v=g1[u][i];
//			cout<<s<<' '<<u<<' '<<v<<' '<<dis[u]+1<<' '<<dis[v];
			if(dis[v]==dis[u]+1)
			{
				num[v]++;
				q.push(v);
//				cout<<" 111111111111";
//				cout<<s<<' '<<v<<' '<<dis[v]<<endl;
			}
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				num[v]++;
				q.push(v);
			}
//			cout<<endl;
		}
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		if(c<=10)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				cin>>x[i];
				g1[i].clear();
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i==j)continue;
					if(abs(x[i]-x[j])<=d)g1[i].push_back(j);
//					else break;
//					cout<<i<<' '<<j<<endl;
				}
			}
//			for(int u=1;u<=n;u++)
//			{
//				for(int i=0;i<g1[u].size();i++)
//				{
//					int v=g1[u][i];
//					cout<<u<<' '<<v<<endl;
//				}
//			}
			ans=0;
			for(int i=1;i<=n;i++)
			{
				bfs(i);
//				cout<<endl;
				for(int j=1;j<=n;j++)
				{
					if(i==j)continue;
					if(num[j]==2)ans++;
//					cout<<i<<' '<<j<<' '<<num[j]<<endl;
				}
			}
			cout<<ans/2<<endl;
		}
	}
	return 0;
 } 
 /*
0 1
5 3
-3 0 2 3 4
 */
