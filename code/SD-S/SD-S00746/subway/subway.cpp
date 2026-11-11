#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pll pair<long,long>
const int N=1e5+10;
const int LINF=0x3F3F3F3F3F3F3F3F;
const int INF=0x3F3F3F3F;
inline int read()
{
	int ans=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*f;
}
using namespace std;
int c,n,m,d,q;
int w[N]; 
vector<pair<int,int>> v[N];
int dis[N];
int bfs(int bg,int ed)
{
	for(int i=1;i<=(m+n);i++) dis[i]=INF;
	priority_queue<pll,vector<pll>,greater<pll>> q;
	q.push({0,bg});
	dis[bg]=0;
	while(!q.empty())
	{
		pll a=q.top();
		q.pop();
		for(auto x:v[a.second])
		{
			if(dis[x.second]>dis[a.second]+x.first)
			{
				dis[x.second]=dis[a.second]+x.first;
				q.push({dis[x.second],x.second});
				//cout<<dis[x.second]<<"--"<<x.second<<endl;
			}
		}
	} 
	return dis[ed];
}
void solve()
{
	 c=read(),n=read(),m=read(),d=read(),q=read(); 
	for(int i=1;i<=m;i++) w[i]=read();
	int xx,yy,k;
	for(int i=1;i<=n;i++)
	{
		k=read();
		for(int j=1;j<=k;j++)
		{
			xx=read(),yy=read();
			v[(m+i)].push_back({yy,xx});
			v[xx].push_back({yy,(m+i)});
		}
	}
	while(q--)
	{
		xx=read(),yy=read();
		cout<<w[xx]+w[yy]+bfs(xx,yy)<<endl; 
		//for(int i=1;i<=(m+n);i++) cout<<dis[i]<<endl;
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T=1;
	//T=read();
	while(T--) solve(); 
	return 0;
}
/*


*/
