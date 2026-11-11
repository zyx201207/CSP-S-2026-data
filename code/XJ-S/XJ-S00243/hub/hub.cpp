#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN=1e6+100;
int n,m,a[MAXN],b[MAXN];
vector<int> e[MAXN];
int f[MAXN],g[MAXN],num[MAXN],mx[MAXN],dp[MAXN],mxx,res;
void dfs1(int u,int fa,int r)
{
	//cout<<"---------now "<<u<<endl;
	if(e[u].size()==1&&e[u][0]==fa)
	{
		g[u]=0;
		return;
	}
	int gmin=0;
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];
		if(v==fa)continue;
		dfs1(v,u,r);
		g[u]=max(g[u],g[v]+1);
		gmin=min(gmin,g[v]+1);
		//cout<<"??? "<<u<<" "<<v<<" "<<g[v]<<" "<<g[u]<<endl;
		f[u]+=f[v];
	}
	if(gmin<0&&g[u]<-gmin)g[u]=gmin;
	//cout<<"LOOK "<<u<<" "<<f[u]<<" "<<g[u]<<endl;
	if(g[u]>=r||(u==1&&g[u]>0))
	{
		g[u]=-r;
		f[u]++;
		a[u]++;
	}
	
}
void dfs2(int u,int fa)
{
	num[u]=a[u];
	if(a[u]==0)mx[u]=1;
	int sc=0;
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];
		if(v==fa)continue;
		dfs2(v,u);
		num[u]+=num[v];
		dp[u]+=dp[v];
		if(num[v]>0)sc++;//,cout<<"WHAT "<<u<<" "<<v<<endl;
	}
	if(sc>1)b[u]=1;
	if(num[u]!=0)dp[u]++;
	//cout<<"MOD "<<u<<" "<<dp[u]<<endl; 
	int mxnow=-1,mxnow2=-1,mxnowid=0;
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];
		if(v==fa||num[v]==0||a[v])continue;
		if(mx[v]>mxnow)mxnowid=v;
		mxnow=max(mxnow,mx[v]);
		//cout<<"SEARCH "<<v<<endl;
	}
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];
		if(v==fa||v==mxnowid||num[v]==0||a[v])continue;
		mxnow2=max(mxnow2,mx[v]);
	}
	if(mxnow==-1)return;
	else if(mxnow2==-1)mx[u]=mxnow+1;
	else mx[u]=mxnow+mxnow2+1;
	//mx[u]=mxnow+mxnow2;
	//cout<<"NOW "<<u<<" "<<mx[u]<<" "<<mxnow<<" "<<mxnow2<<endl;
	mxx=max(mxx,mx[u]);
	
}
bool check(int x)
{
	memset(f,0,sizeof(f));
	//memset(g,0x3f,sizeof(g));
	for(int i=1;i<=n;i++)g[i]=-1e8;
	memset(num,0,sizeof(num));
	memset(dp,0,sizeof(dp));
	memset(mx,0,sizeof(mx));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	mxx=0;
	res=0;
	dfs1(1,0,x);
	dfs2(1,0);
	if(mxx>0)mxx--;
	int lenall=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>0||b[i]>0)lenall=max(lenall,dp[i]);
	}
	/*cout<<"INFO "<<x<<" "<<f[1]<<" "<<lenall<<" "<<mxx<<endl;
	for(int i=1;i<=n;i++)
	if(a[i])cout<<i<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++)
	if(a[i]||b[i])cout<<i<<" ";
	cout<<endl;*/
	//for(int i=1;i<=n;i++)cout<<mx[i]<<endl;
	
	return lenall-mxx<=m;
}
void solve(int id)
{
	cin>>n>>m;
	for(int i=0;i<=n;i++)e[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int l=1,r=n,ans=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	//cout<<"ANS "<<ans<<endl;
	cout<<ans<<endl;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)solve(c);
	return 0;
}
