#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int> 
using namespace std;
const int N=2e6+10;
int n,D,d[N],cnt[N],x[N];
bool vis[N];
vector<int> g[N];
priority_queue<PII,vector<PII>,greater<PII> > q;
void dij(int s){
	for(int i=1;i<=n;i++){
		d[i]=1e18;
		vis[i]=0;
	}
	d[s]=0;cnt[s]=1;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u])continue;
		for(int v:g[u]){
			if(d[u]+1<d[v]){
				d[v]=d[u]+1;
				cnt[v]=cnt[u];
				q.push({d[v],v});
			}else if(d[u]+1==d[v]){
				cnt[v]+=cnt[u];
			}
		}
	}
}
void solve(){
	cin>>n>>D;
	int ans=0;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=D){
					g[i].push_back(j);
				}else{
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			dij(i);
			for(int j=1;j<=n;j++)if(cnt[j]==2)ans++;
		}
		cout<<ans<<"\n";
	}else{
		int flag=1,sub=x[2]-x[1];
		for(int i=1;i<n;i++)if(x[i+1]-x[i]!=sub)flag=0;
	//	cout<<n<<" "<<sub<<" "<<D<<endl;
		if(flag){
			if(sub*2>D){
				cout<<"0\n";
			}else{
				ans=n-D/sub*2+1;
				cout<<max(ans,0LL)<<"\n";
			}
		}else{
			cout<<"0\n";
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)solve();
	
	return 0;
}
