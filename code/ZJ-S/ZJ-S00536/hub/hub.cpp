#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define DEP(i,a,b) for(int i=(a);i>=(b);i--)
#define REPc(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define DEPc(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define MOD(a) (((a)%mod+mod)%mod)
#define ADD(a,b) (a)=(mod+(a)+(b))%mod
#define SUB(a,b) (a)=(mod+(a)-(b))%mod
#define MUL(a,b) (a)=(1ll*(a))*((b)%mod)%mod
#define MAX(a,b) (a)=max((a),(b))
#define MIN(a,b) (a)=min((a),(b))
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define INF 2000000000
using namespace std;
int index;
namespace WuJy{
	const int N=2e6+5;
	int n,k,ans=0;
	vector<int>adj[N];
	bitset<N>is;
	int fa[N];
	int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
	int get(int u,int fa,int dep,int&d){
		if(is[u])MIN(d,dep);
		for(int v:adj[u])if(v^fa)get(v,u,dep+1,d);
	}
	void dfs(int x,int cnt){
		if(cnt==k){
			REP(i,1,n)fa[i]=i;
			REP(i,1,n)if(is[i])
				for(int v:adj[i])if(is[v])
					fa[find(i)]=find(v);
			int o1=0,o2=0,f=1;
			REP(i,1,n)if(is[i]){
				int oo=find(i);
				if(!o1)o1=oo;
				else if(o1!=oo){
					if(!o2)o2=oo;
					else if(o2!=oo){
						f=0;
						break;
					}
				}
			}
			if(f){
				int tmp=0;
				REP(i,1,n)if(!is[i]){
					int x=INF;get(i,0,0,x);
					MAX(tmp,x);
				}
				MIN(ans,tmp);
			}
			return;
		}
		if(x==n+1)return;
		is[x]=1;dfs(x+1,cnt+1);
		is[x]=0;dfs(x+1,cnt);
	}
	void main(){
		cin>>n>>k;
		REP(i,2,n){
			int u,v;cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		ans=INF;dfs(1,0);
		cout<<ans<<'\n';
		REP(i,1,n)adj[i].clear();
	}
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T=1;cin>>index>>T;
	while(T--)WuJy::main();
	return 0;
}
