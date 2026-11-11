#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int N=5e5+5;
int c,n,m,d,q;
int w[N];
vector<pii> g[N*21];
bool vis[N*21];
int dis[505][505];
int D[N*21];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		bool f=0;
		int x,b,t;
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			int bb,tt;
			cin>>bb>>tt;
			int tmp=i*m;
			if(!f)
				f=1;
			else
			{
				g[b+tmp].push_back({bb+tmp,0});
				g[bb+tmp].push_back({b+tmp,0});
			}
			
			g[bb].push_back({bb+tmp,tt});
			g[bb+tmp].push_back({bb,tt});
			b=bb,t=tt;
		}
	}
	
//	for(int i=1;i<=(n+m)*2;i++)
//	{
//		cout<<i<<":";
//		for(auto j:g[i])
//			cout<<j.first<<" ";
//		cout<<endl;
//	}
	
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(dis[x][y])	cout<<dis[x][y]+w[x]+w[y]<<"\n";
		else
		{
			priority_queue<pii,vector<pii>,greater<pii> > qr;
			memset(D,0x3f,sizeof D);
			memset(vis,0,sizeof vis);
			qr.push({0,x});
			D[x]=0;
			int cnt=0;
			while(!qr.empty())
			{
				cnt++;
				pii u=qr.top();
				qr.pop();
				int val=u.first;
				int pos=u.second;
				
				if(vis[pos])	continue;
				vis[pos]=1;
//				cout<<"\n"<<pos<<"\n";
				for(auto j:g[pos])
				{
//					cout<<"！！！！！！！！！！！！"<<"\n";
					int nxt=j.first;
					int v=j.second;
//					cout<<endl<<nxt<<" "<<v;
					if(D[pos]+v < D[nxt])
					{
						D[nxt]=D[pos]+v;
						qr.push({D[nxt],nxt});
					}
				}
			}
//			cout<<cnt<<"\n";
//			for(int i=1;i<=m;i++)	cout<<D[i]<<" ";
//			cout<<endl;
			
			for(int k=1;k<=m;k++)
			{
				if(D[k]!=0x3f3f3f3f)
				{
					if(dis[x][k])
					{
						dis[x][k]=min(dis[x][k],D[k]);
					}
					else
					{
						dis[x][k]=D[k];
					}
				}
			}
			cout<<dis[x][y]+w[x]+w[y]<<"\n";
		}
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
