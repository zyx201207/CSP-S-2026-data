#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,ll>
#define p(i,j) make_pair(i,j)
#define DEBUG_CODE 0
#define NDB if(!DEBUG_CODE)
#define DB if(DEBUG_CODE)
using namespace std;
const int N=2e6+10;
const ll mod=1e18+7;
ll n,m,x,y,z,sum,ans,cnt[N],tot,k,T,u,v,w,l,r,opt,a[N],c,dis[N];
priority_queue<pii ,vector<pii >,greater<pii > > q;
vector<int> e[N];
int dij(int s){
	for(int i=1;i<=n;i++) dis[i]=mod,cnt[i]=0;
	cnt[s]=1,dis[s]=0;
	while(!q.empty()) q.pop();
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		for(auto v:e[u]){
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				q.push({dis[v],v});
			}else if(dis[u]+1==dis[v]){
				cnt[v]+=cnt[u];
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) if(cnt[i]==2) ans++;
	return ans;
}
int main(){
	NDB{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	}
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i],e[i].clear();
		sum=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j&&abs(a[i]-a[j])<=m) e[i].push_back(j);
		for(int i=1;i<=n;i++) sum+=dij(i);
		cout<<(sum>>1)<<"\n";
	}
	return 0;
}

