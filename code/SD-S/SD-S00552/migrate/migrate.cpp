#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
const int N=2e6+5;
ll a[N];
int c,T,n,d;
vector<pii> g[N];
bool vis[N];
int dis[N];
int tim[N];
int ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopem("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)	cin>>a[i];
		sort(a+1,a+n+1); 
		if(a[1]<0)
		{
			int tmp=abs(a[1]);
			for(int i=1;i<=n;i++)	a[i]+=tmp;	
		}
		for(int i=1;i<=n;i++)	g[i].clear();
		for(int i=1;i<=n;i++)
		{
			for(int k=i+1;k<=n;k++)
			{
				if(a[k]-a[i]<=d)
				{
					g[i].push_back({k,1});
				}
				else	break;
			}
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			priority_queue<pii,vector<pii>,greater<pii> > q;
			q.push({0,i});
			memset(dis,0x3f,sizeof dis);
			memset(tim,0,sizeof tim);
			dis[i]=0;
			while(!q.empty())
			{
				pii u=q.top();
				q.pop();
				int pos=u.second;
				int val=u.first;
//				cout<<"！！！！！！！！！！"<<"\n";
				for(auto j:g[pos])
				{
//					cout<<"！！！！！！！！！！"<<"\n";
					int v=j.second;
					int nxt=j.first;
					if(nxt<=pos)	continue;
					if(dis[nxt] == dis[pos]+v)
					{
						tim[nxt]++;
					}
					else if(dis[nxt] > dis[pos]+1)
					{
//						cout<<"！！！！！！！！！！"<<"\n";
						tim[nxt]=1;
						dis[nxt]=dis[pos]+1;
						q.push({dis[nxt],nxt});
					}
				}
			}
			for(int i=1;i<=n;i++)
				if(tim[i]==2)	ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
