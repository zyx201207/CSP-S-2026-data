#include<bits/stdc++.h>
//#define int long long
using namespace std;

//inline int read()
//{
//	int x=0,f=1;
//	char c=getchar();
//	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
//	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
//	return x*f;
//}
const int M=5*1e5+10;

int c,n,m,d,q,t;
int w[M];
int road[505][M];
vector<int>a[M];
bool dis[M];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int x;
		cin>>x>>t;
		road[i][x]=t;
		for(int j=2;j<=k;j++)
		{
			int xx=x;
			cin>>x>>t;
			road[i][x]=t;
			a[xx].push_back(x);
			a[x].push_back(xx);
		}
	}
	for(int p=1;p<=q;p++)
	{
		bool o=1;
		long long minn=1e18;
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=n;i++)
		{
			if(road[i][x]&&road[i][y])
			{
				o=0;
				if(road[i][x]+road[i][y]<minn)minn=road[i][x]+road[i][y];
			}
		}
		if(!o)cout<<minn+w[x]+w[y]<<"\n";
		else
		{
			minn=0;
			for(int i=1;i<=m;i++)dis[i]=0;
			dis[x]=1;
			queue<pair<int,int>>q;
			q.push({x,0});
			while(!q.empty())
			{
				int d=q.front().first,sum=q.front().second;
				if(d==y)
				{
					minn=sum;
					break;
				}
				q.pop();
				for(int i=0;i<a[d].size();i++)
				{
					if(dis[a[d][i]])continue;
					dis[a[d][i]]=1;
					q.push({a[d][i],sum+1});
				}
				
			}
			cout<<minn*t+w[x]+w[y]<<"\n";
		}
	}
	
	
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 1 2 1 4 1
//3 2 1 3 1 5 1
//1 3
//1 2
