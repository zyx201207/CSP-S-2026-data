#include "bits/stdc++.h"
#define int long long
#define REP(i,j,k) for(long long i=j;i<=k;i++)
#define gc() getchar()
#define pc(i) putchar(i)
using namespace std;

typedef pair<int,int> pii;
int Cc,n,m,d,q;
const int MAXN=550;
const int MAXM=5e5+20;
const int MAXQ=5e5+20;
const int INF=0x3f3f3f3f3f3f3f3f;
int w[MAXM];
int kk[MAXN];
vector<int> a[MAXN];
vector<int> t[MAXN];
vector<pii> bel[MAXM];
int dis[MAXN][MAXN];
int ew[MAXN][MAXN];
void floyed(){
	REP(i,1,n){
		dis[i][i]=ew[i][i]=0;
	}
	REP(i,1,n){
		REP(j,1,n){
			dis[i][j]=min(dis[i][j],ew[i][j]);
		}
	}
	REP(k,1,n){
		REP(i,1,n){
			REP(j,1,n){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0) -> ios::sync_with_stdio(0);
	cin>>Cc>>n>>m>>d>>q;
	REP(i,1,m){
		cin>>w[i];
	}
	REP(i,1,n){
		cin>>kk[i];
		REP(j,1,kk[i]){
			int tmp1,tmp2;cin>>tmp1>>tmp2;
			a[i].push_back(tmp1);
			t[i].push_back(tmp2);
			bel[tmp1].push_back({i,tmp2});
		}
	}
	memset(ew,0x3f,sizeof(ew));
	memset(dis,0x3f,sizeof(dis));
	REP(i,1,n){
		REP(j,0,kk[i]-1){
			int u=a[i][j];
			int len=bel[u].size()-1;
			REP(k,0,len){
				auto tmp=bel[u][k];
				if(ew[i][tmp.first]>t[i][j]+tmp.second){
					ew[i][tmp.first]=t[i][j]+tmp.second;
				}
			}
		}
	}
	floyed();
	REP(i,1,q){
		int u,v;
		cin>>u>>v;
		int len1=bel[u].size()-1;
		int len2=bel[v].size()-1;
		int ans=INF;
		REP(a1,0,len1){
			REP(a2,0,len2){
				int aa1=bel[u][a1].first;
				int aa2=bel[v][a2].first;
				int ab1=bel[u][a1].second;
				int ab2=bel[v][a2].second;
				ans=min(ans,dis[aa1][aa2]+ab1+ab2);
			}
		}
		ans+=w[u]+w[v];
		cout<<ans<<'\n';
	}
	return 0;
}