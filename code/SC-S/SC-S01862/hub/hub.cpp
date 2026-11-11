#include<bits/stdc++.h>
#define fir first
#define sec second
#define int long long
#define pii pair<int,int>
#define tomin(a,b) a=min(a,b)
#define tomax(a,b) a=max(a,b)
#define fep(i,s,e) for(int i=s;i<e;i++)
#define pef(i,s,e) for(int i=s;i>e;i--)
#define rep(i,s,e) for(int i=s;i<=e;i++)
#define per(i,s,e) for(int i=s;i>=e;i--)
using namespace std;
const int N=100;
const int inf=1e18;
int c,T,n,k,G[N][N];
int col[N],cnt,g[N];
int f[N][N];
map<int,int>mp;
int find(int u){
	if(u==g[u])return u;
	return g[u]=find(g[u]);
}
void join(int u,int v){
	int fu=find(u);
	int fv=find(v);
	if(fu==fv)return;
	g[fu]=fv;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		int ans=inf;
		rep(i,1,n){
			rep(j,1,n)G[i][j]=inf;
			G[i][i]=0;
		}
		fep(i,1,n){
			int u,v;cin>>u>>v;
			G[u][v]=G[v][u]=1;
		}
		rep(mid,1,n){
			rep(j,1,n){
				rep(k,1,n){
					tomin(G[j][k],G[j][mid]+G[mid][k]);
				}
			}
		}
//		rep(i,1,n){
//			rep(j,1,n){
//				cout<<G[i][j]<<" ";
//			}cout<<"\n";
//		}
		fep(i,0,(1<<n)){
			cnt=0;
			rep(j,1,n){
				if(i&(1<<(j-1)))col[j]=1,cnt++;
				else col[j]=0;
			}
			if(cnt!=k)continue;
			rep(j,1,n)g[j]=j;
			rep(j,1,n){
				rep(k,j+1,n){
					if(col[j]==1&&col[k]==1&&G[j][k]==1){
						join(j,k);
					}
				}
			}
			int tot=0;
			mp.clear();
			rep(j,1,n){
				if(col[j]==1){
					if(mp[g[j]]==1)continue;
					mp[g[j]]=1;tot++;
				}
			}
			if(tot>2)continue;
			int res=0;
			rep(j,1,n){
				int cur=inf;
				rep(k,1,n){
					if(col[k]==1)tomin(cur,G[j][k]);
				}
				tomax(res,cur);
			}
			tomin(ans,res);
		}
		cout<<ans<<"\n";
	}
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/