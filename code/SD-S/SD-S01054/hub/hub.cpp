#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read();
const int N=1e6+10;
int c,T,n,k,go[N][25],dep[N];
bool ez[15][15],in[15];int usd[15];
vector<int>g[N];
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;go[u][0]=fa;
	for(int i=1;(1<<i)<=dep[u];i++)
		go[u][i]=go[go[u][i-1]][i-1];
	for(auto v:g[u]){
		if(v==fa)continue;
		dfs(v,u);
	}
}int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=19;i>=0;i--)
		if(dep[go[x][i]]>=dep[y])x=go[x][i];
	if(x==y)return x; 
	for(int i=19;i>=0;i--)
		if(go[x][i]!=go[y][i])x=go[x][i],y=go[x][i];
	return go[x][0];
}int dis(int x,int y){
	int l=lca(x,y);
	return dep[x]+dep[y]-2*dep[l];
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),T=read();
//	cout<<__lg(1000000);
	while(T--){
		for(int i=1;i<=n;i++)g[i].clear();
		n=read(),k=read();
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			g[u].push_back(v);
			g[v].push_back(u);
			ez[u][v]=ez[v][u]=1;
		}dfs(1,0);
		int ans=0x3f3f3f3f;
		if(c<=3){
			vector<int>S;
			for(int s=0;s<(1<<n);s++){
				if(__builtin_popcount(s)!=k)continue;
				
				S.clear();
				for(int i=1;i<=n;i++){
					if(s&(1<<(i-1)))S.push_back(i),in[i]=1;
					else in[i]=0; 
					usd[i]=0;
				}int res=0,tot=0;
				queue<int>q;
				for(auto x:S){
					if(!usd[x])q.push(x),tot++;;
					
					while(!q.empty()){
						int u=q.front();q.pop();
						usd[u]=tot;
						for(auto v:g[u]){
							if(in[v]){
								if(!usd[v])usd[v]=tot,q.push(v);
							}
						}
					}
				}//if(tot<=2)cout<<"!";
				if(tot>2)continue;
				
				for(int i=1;i<=n;i++){
					int mn=0x3f3f3f3f;
					for(auto j:S)
						mn=min(mn,dis(i,j));
					res=max(res,mn);
				}//cout<<res<<'\n';
				ans=min(ans,res);
			}cout<<ans<<'\n';
		}else if(c==13||c==14){
			
		}
	}
	return 0;
}
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}


