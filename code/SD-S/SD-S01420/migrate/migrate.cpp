#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
int n,mx;
int a[100010],d[10010];
bool vis[10010];
void dijk(int ed){
	priority_queue<PII,vector<PII>,greater<PII> > q;
	q.push({0,1});
	fill(d+1,d+1+n,1e9);
	fill(vis+1,vis+1+n,0);
	d[1]=0;
	while(!q.empty()){
		PII t=q.top();
		q.pop();
		int v=t.second;
		if(vis[v]) continue;
		vis[v]=1;
		for(int i=v+1;i<=ed;i++){
			if(d[i]>d[v]+1 and abs(a[i]-a[v])<=mx){
				d[i]=d[v]+1;
				q.push({d[i],i});
			}
		} 
	}
}
void solve(){
	int ans=0;
	cin>>n>>mx;
	for(int i=1;i<=n;i++) cin>>a[i];
	dijk(n);
	for(int i=2;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j) continue;
			if(d[j]==d[i]) ans++;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--) solve();
	return 0;
} 
