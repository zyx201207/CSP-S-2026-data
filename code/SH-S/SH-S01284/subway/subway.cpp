#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int M=500010;
int c,m,n,d,q;
int ta[M];
long long dis[N][N];
vector<pair<int,int>>edges[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//cin>>c>>n>>m>>d>>q;//n->sunway m->station 
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	//auto a=clock();
	for(int i=1;i<=m;i++)
	{
		//cin>>ta[i];
		scanf("%d",&ta[i]);
	}
	//cout<<"n="<<n<<" m="<<m<<endl;
	
	//auto b=clock();
	//cout<<b-a<<endl;
	
	for(int i=1;i<=n;i++)//init
	{
		//cout<<i<<endl;
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=1e18;
			if(i==j)dis[i][j]=0;
		}
	} 
	
	//auto c=clock();
	//cout<<c-b<<endl;
	
	//cout<<1<<endl;
	for(int i=1;i<=n;i++)
	{
		//cout<<i<<endl;
		int k;
		//cin>>k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int z,tb;
			//cin>>z>>tb; 
			scanf("%d%d",&z,&tb);
			edges[z].push_back(make_pair(i,tb));
			//cout<<z<<" ";
		}
		//cout<<endl;
	}
	
	//auto d=clock();
	//cout<<d-c<<endl;
	
	for(int i=1;i<=m;i++)//for every station: check the lines passing it and give distance
	{
		int len=edges[i].size();
		//cout<<i<<".size:"<<len<<endl;
		for(int j=0;j<len;j++)
		{
			for(int k=0;k<j;k++)
			{
				int u=edges[i][j].first,v=edges[i][k].first;
				int w1=edges[i][j].second,w2=edges[i][k].second;
				//cout<<i<<" "<<j<<" "<<k<<" "<<u<<" "<<v<<" "<<w1+w2<<endl;
				dis[u][v]=min(dis[u][v],0LL+w1+w2);
				dis[v][u]=dis[u][v];
			}
		}
	}
	
	//auto e=clock();
	//cout<<e-d<<endl;
	
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(dis[i][j]<=1e9)cout<<dis[i][j]<<" ";
			else cout<<-1<<" ";
		}
		cout<<endl;
	}
	//*/
	for(int l=1;l<=n;l++)
	{
		//cout<<l<<endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
			}
		}
	}
	
	//auto f=clock();
	//cout<<f-e<<endl;
	
	//getchar();
	for(int i=1;i<=q;i++)
	{
		//cout<<i<<endl;
		int a,b;
		//cin>>a>>b;
		scanf("%d%d",&a,&b);
		//cout<<a<<" "<<b<<endl;
		int w=ta[a]+ta[b];
		long long ans=1e18;
		for(auto y:edges[a])
		{
			//cout<<a<<" "<<y<<" "<<endl;
			//cout<<edges[a][y].first<<endl;
			for(auto z:edges[b])
			{
				ans=min(ans,dis[y.first][z.first]+w+y.second+z.second);
			}
		}
		//cout<<ans<<endl;
		printf("%lld\n",ans);
	 } 
	return 0;
} 
