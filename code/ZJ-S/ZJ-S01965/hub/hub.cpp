// hub
#include<bits/stdc++.h>
bool Mst;
using namespace std;
using ll=long long;
//#define int ll
using pii=pair<int,int>;
const int N=2e6+5;
vector<int> g[N];
int dfn[N],rnk[N],dp[N],ocnt;
pii st[25][N];
void predfs(int u,int fa)
{
	st[0][++ocnt]={dp[u],u};
	rnk[dfn[u]=ocnt]=u;
	for(int v:g[u]) if(v!=fa) dp[v]=dp[u]+1,predfs(v,u),st[0][++ocnt]={dp[u],u};
}
void stinit()
{
	for(int k=1;k<=20;k++)
		for(int i=1;i+(1<<(k-1))<=ocnt;i++)
			st[k][i]=min(st[k-1][i],st[k-1][i+(1<<(k-1))]);
}
int lca(int u,int v)
{
	u=dfn[u],v=dfn[v];
	if(u>v) swap(u,v);
	int k=__lg(v-u+1);
	return min(st[k][u],st[k][v-(1<<k)+1]).second;
}
int n,k;
int mxdp[N],sum[N];
void dfs(int u,int fa)
{
	mxdp[u]=0;
	for(int v:g[u]) if(v!=fa)
	{
		dfs(v,u);
		mxdp[u]=max(mxdp[u],mxdp[v]+1);
	}
	sum[mxdp[u]]++;
}
int co[N],fl[N];
vector<int> vec;
void color(int u,int fa,int dep)
{
	if(dep==0) return vec.push_back(u),fl[u]=1,void();
	int cc=0;
	for(int v:g[u]) if(v!=fa) color(v,u,dep-1),cc++;
//	if(!cc) vec.push_back(u);
}
int dfsget(int u,int fa,int dd)
{
	int dep=0;
	for(int v:g[u]) if(v!=fa) dep=max(dep,dfsget(v,u,dd)+1);
//	cout<<"? "<<u<<" "<<dep<<" "<<dd<<"\n";
	if(dep==dd) vec.push_back(u),fl[u]=1;
	return dep;
}
void dfscnt(int u,int fa)
{
	for(int v:g[u]) if(v!=fa)
	{
		dfscnt(v,u);
		fl[u]|=fl[v];
	}
}
bool Med;
signed main()
{
//	cerr<<abs((&Med)-(&Mst))/1024.0/1024.0<<" MB"<<endl;
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int cid,tc;cin>>cid>>tc;
	while(tc--)
	{
		cin>>n>>k;
		int ans=1e9+5;
		for(int i=1,u,v;i<n;i++) cin>>u>>v,g[u].push_back(v),g[v].push_back(u);
		for(int rt=1;rt<=n;rt++)
		{
//			cout<<"!!!"<<rt<<"\n";
			for(int i=1;i<=n;i++) dfn[i]=rnk[i]=dp[i]=mxdp[i]=0;
			ocnt=0,predfs(rt,0);
			stinit();
			for(int u:g[rt])
			{
//				cout<<"!!"<<u<<"\n";
				dfs(u,rt);
				for(int i=mxdp[u];i>=0;i--) sum[i]+=sum[i+1];
//				cout<<"mxdp: ";
//				for(int i=0;i<=mxdp[u];i++) cout<<sum[i]<<" ";
//				cout<<"\n";
				int le=1,ri=n,res=n;
				while(le<=ri)
				{
					int mid=(le+ri)/2,ss=0;
//					cout<<"!"<<mid<<"\n";
					for(int i=1;i<=n;i++) co[i]=fl[i]=0;
					vec.clear();
					color(rt,u,mid*2-1);
//					cerr<<"#\n";
					dfsget(rt,u,mid);
					if(vec.size())
					{
//						cerr<<"#\n";
						sort(vec.begin(),vec.end(),[&](int x,int y){return dfn[x]<dfn[y];});
//						cout<<"vec: ";
//						for(int x:vec) cout<<x<<" ";
//						cout<<"\n";
//						cerr<<"#\n";
						int cc=lca(vec.front(),vec.back());
//						cout<<cc<<"\n";
						dfscnt(cc,0);
//						cerr<<"#\n";
						for(int i=1;i<=n;i++) ss+=fl[i];
					}
//					cout<<ss<<" "<<sum[mid]<<"\n";
					if(ss+sum[mid]<=k) res=mid,ri=mid-1;
					else le=mid+1;
				}
				ans=min(ans,res);
				for(int i=0;i<=mxdp[u];i++) sum[i]=0;
//				cout<<"->"<<res<<"\n";
			}
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++) g[i].clear();
	}
//	cerr<<clock()<<endl;
}

/*
0 1
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
*/
