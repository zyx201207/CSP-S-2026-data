#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define f(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define pii pair<int,int>
#define fi first
#define se second
const int N=5000+6,M=5e5+6;
int x[N];int cnt[N];
int dis[N];
int n,d;
vector<int> g[N];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>d;
		f(i,1,n)cin>>x[i],g[i].clear();
		int ans=0;
		f(i,1,n)f(j,i+1,n){
			if(abs(x[i]-x[j])<=d)g[i].push_back(j),g[j].push_back(i);
		}
		f(i,1,n){
			f(j,1,n)dis[j]=-1,cnt[j]=0;
			dis[i]=0;cnt[i]=1;
			queue<int> q;q.push(i);
			while(!q.empty()){
				int now=q.front();q.pop();
				for(int u:g[now]){
					if(dis[u]==-1){
						dis[u]=dis[now]+1;
						cnt[u]=cnt[now];q.push(u);
					}else{
						if(dis[u]==dis[now]+1){
							cnt[u]+=cnt[now];
						}
					}
				}
			}
			f(j,i+1,n)if(cnt[j]==2)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}