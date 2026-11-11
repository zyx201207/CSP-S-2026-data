/*
20261031
T   W   D
79  15  15
	8	22
W   17:43
D	17:51
F	18:13
*/
#include<iostream>
#include<vector>
using namespace std;
const int N=1e6+5;
vector<int>G[N];
int X,n,m,res,d[2][N],f[2][N];
void gf(int u,int fa)
{
	f[0][u]=f[1][u]=d[0][u]=d[1][u]=0;
	for(int v:G[u])if(v!=fa)
	{
		gf(v,u),f[0][u]+=f[0][v];
		if(d[0][v]+1>d[0][u])d[1][u]=d[0][u],d[0][u]=d[0][v]+1;
		else d[1][u]=max(d[1][u],1+d[0][v]);
	}
	f[1][u]=f[0][u]+1,f[0][u]+=d[0][u]>=X;
}
void gr(int u,int fa,int w,int de,int lim)
{
	if(res||lim<0||w>=m)return;
	if(w+f[1][u]<=m){res=1;return;}
	for(int v:G[u])if(v!=fa)
	{
		int dd=d[d[0][v]+1==d[0][u]][u];
		if(de+dd<=X)gr(v,u,w,de+1,lim-1);
		else gr(v,u,w,de+1,min(lim-1,X-dd-1));
	}
}
int chkk(int x)
{
	res=0,gf(x,0);
	if(f[1][x]<=m)return 1;
	for(int v:G[x])gr(v,x,f[1][x]-f[0][v],1,n+1);
	return res;
}
int chk(int x){X=x;for(int i=1;i<=n;++i)if(chkk(i))return 1;return 0;}
void ATRI()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)G[i].clear();
	for(int i=1,u,v;i<n;++i)cin>>u>>v,G[u].push_back(v),G[v].push_back(u);
	int l=0,r=n,res=-1;
	while(l<=r){int mid=l+r>>1;if(chk(mid))res=mid,r=mid-1;else l=mid+1;}
	cout<<res<<"\n";
}
int main()
{
	ios::sync_with_stdio(),cin.tie(0),cout.tie();
	int c,t;cin>>c>>t;while(t--)ATRI();
	return 0;
}