#include  <bits/stdc++.h>
#define MAXN int(2e6+5)
using namespace std;
long long x[MAXN];
//bool vis[MAXN];
long long MMIN=1e12;
long long CNT=0;
long long n,d;
void dfs(long long depth,long long pos,long long end)
{
	
	if(pos==end)
	{
		//vis[pos]=false;
	//	cout<<depth<<" "<<MMIN<<endl;
		if(depth==MMIN)	CNT++;
		
		if(MMIN>depth)
		{
			CNT=0;
			MMIN=depth;
			//cout<<depth<<" "<<MMIN<<endl;
			return;
		}
		
		return;
	}
	for(long long i=pos+1;i<=end;i++)
	{
		if(d<=abs(x[i]-x[pos]))
		{
		//	vis[i]=true;
			dfs(depth+1,i,end);
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--)
	{
		
		cin>>n>>d;
		for(long long i=1;i<=n;i++)
		{
			cin>>x[i];
		}
	//	memset(vis,false,sizeof(vis));
		long long ans=0;
		for(long long i=1;i<n;i++)
		{
			
			for(long long j=n;j>i;j--)
			{
				CNT=0;
				MMIN=1e12;
				dfs(0,i,j);
				if(CNT==2) ans++;
			}
		}
		cout<<ans<<endl;
	} 
	
	return 0;
}



//#include  <bits/stdc++.h>
//#define MAXN long long(2e6+5)
//
//struct edge
//{
//	int u;
//	int v;
//	long long step;
//	friend bool operator<(const edge& a,const edge& b){
//		return a.step<b.step;
//	}
//};
//using namespace std;
//map<int,long long> mp[MAXN];
//int n;
//priority_queue<edge>q;
//long long x[MAXN];
//int fa[MAXN];
//
//
//int find(int x)
//{
//	if(fa[x]==x) return x;
//	return fa[x]=find(x);
//}
//int main()
//{
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
//	int c,t;
//	cin>>c>>t;
//	
//	while(t--)
//	{
//		int n,d;
//		cin>>n>>d;
//		cin>>x[1];
//		int l=x[1];
//		x[1]=0;
//		for(int i=2;i<=n;i++)
//		{
//			cin>>x[i];
//			x[i]+=-l;
//			if(x[i]<=d)
//			{
//				q.push({1,i,x[i]});
//				mp[1][i]=x[i];
//			} 
//		}
//		
//	}
//	return 0;
//}

