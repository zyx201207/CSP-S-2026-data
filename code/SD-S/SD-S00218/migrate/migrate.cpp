#include<bits/stdc++.h>
#define rep(l,r,i) for(int i=l;i<=r;i++)
#define rrep(l,r,i) for(int i=l;i>=r;i--)
#define rmp(v,mp) for(auto v:mp)
using namespace std;
void fre(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
}namespace ZXY{
	const int N=5007;
	typedef long long ll;
	const int mod=998244353,mod1=1e9+7;
	int c,t;vector<int>g[N];
	int n;ll x[N],d;ll cnt[N],cnt1[N];
	int dis[N];
	void bfs(int s){
		fill(dis+1,dis+n+1,2e9);
		fill(cnt+1,cnt+n+1,0);
		fill(cnt1+1,cnt1+n+1,0);
		dis[s]=0;queue<int>q;
		q.push(s);cnt[s]=1;cnt1[s]=1;
		while(!q.empty()){
			int u=q.front();q.pop();
			rmp(v,g[u]){
				if(dis[v]>dis[u]+1){
					dis[v]=dis[u]+1;
					q.push(v);
					cnt[v]=cnt[u];
					cnt1[v]=cnt1[u];
				}else if(dis[v]==dis[u]+1)
					cnt[v]=(cnt[v]+cnt[u])%mod,
					cnt1[v]=(cnt1[v]+cnt1[u])%mod1;
			}
		}
	}
	void solve(){
		ios::sync_with_stdio(0);
		cin.tie(0);cout.tie(0);
		cin>>c>>t;
		while(t--){
			cin>>n>>d;
			int ans=0;
			rep(1,n,i)g[i].clear();
			rep(1,n,i)cin>>x[i];
			rep(1,n,i){
				rep(i+1,n,j)
					if(llabs(x[i]-x[j])<=d)
						g[i].push_back(j);
			}rep(1,n,i){
				bfs(i);
				rep(i+1,n,j)
					if(cnt[j]==2&&cnt1[j]==2) ans++;
			}cout<<ans<<'\n';
		}
	}
}
int main(){fre();ZXY::solve();}
/*0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/ 

