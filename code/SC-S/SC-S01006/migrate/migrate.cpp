#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int x[N],f[N],pos[N],dis[N],cnt[N];
vector<int> e[N];
void solve(){
	int n,d;cin>>n>>d;
	int ans=0,b=5000;
//	if(n<=b){
		for(int i=1;i<=n;i++) e[i].clear(),cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(x[i]-x[j]>d) break;
				e[i].push_back(j);
			}
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]>d) break;
				e[i].push_back(j);
			}
		}for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) dis[j]=1e18,cnt[j]=0;
			queue<int> q;q.push(i),dis[i]=0,cnt[i]=1;
			while(!q.empty()){
				int u=q.front();q.pop();
				for(auto v:e[u]){
					if(dis[v]==dis[u]+1) cnt[v]+=cnt[u];
					if(dis[v]>dis[u]+1) dis[v]=dis[u]+1,cnt[v]=cnt[u],q.push(v);
				}
			}for(int j=1;j<=n;j++) ans+=(cnt[j]==2);
		}cout<<ans/2<<endl;return;
//	}
//	for(int i=1;i<=n;i++) cin>>x[i],f[i]=1,pos[i]=0;
//	int las=1,nxt=1;
//	for(int i=1;i<=n;i++){
//		while(x[i]-x[las]>d) las++;
//		while(x[nxt+1]-x[i]<=d&&nxt<n) nxt++;
//		cout<<pos[las+1]<<endl;
//		ans+=f[pos[las+1]],pos[nxt]=i;
//		f[i]+=f[las];
//		cout<<i<<" "<<las<<" "<<nxt<<endl;
//	}cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--) solve();
	return 0;
}