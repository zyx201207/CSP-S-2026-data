#include<bits/stdc++.h>
#define pii pair<int,int>
#define i1 first
#define i2 second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef double db;
const int N=2e6+9,INF=0x3f3f3f3f;
int c,t,n,dd,x[N],d[N],ct[N];
vector<int> g[N];
void dij(int r){
	memset(d,INF,sizeof(d)); d[r]=0;
	memset(ct,0,sizeof(ct));
	priority_queue<pii,vector<pii>,greater<pii>> q;
	q.push({r,0});
	while(!q.empty()){
		int u=q.top().i1,dt=q.top().i2; q.pop();
		for(int v:g[u]){
			if(d[v]==dt+1) ct[v]++;
			if(d[v]>dt+1){
				d[v]=dt+1; ct[v]=1;
				q.push({v,dt+1});
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>dd;
		for(int i=0;i<=n;i++) g[i].clear();
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[i]-x[j])<=dd){
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			dij(i);
			for(int j=1;j<=n;j++){
				ans+=(ct[j]==2);
			}
		}
		cout<<ans/2<<endl;
	}
	return 0;
}
