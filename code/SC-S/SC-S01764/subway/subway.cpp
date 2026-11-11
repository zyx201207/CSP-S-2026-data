#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e5+5;
int c,n,m,d,q,t[N],x,y,ans=10000000000;
vector<pair<int,int> > g1[N],g2[N];

//void bfs(int x,int y)
//{
//	queue<int> q;
//	q.push(x);
//	while(q.size())
//	{
//		int u=q.front();
//		q.pop();
//		for(auto i:g1[u])
//		{
//			int v=i.first;
//			
//		}
//	}
//}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>t[i];
	for(int i=1;i<=n;i++)
	{
		int k,a,b;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a>>b;
			g1[a].push_back({i,b});
			g2[i].push_back({a,b});
			ans=min(ans,b);
		}
	}
	while(q--)
	{
		cin>>x>>y;
		ans*=2;
		ans+=t[x]+t[y];
		//bfs(x,y);
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
