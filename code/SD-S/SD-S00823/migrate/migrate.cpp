#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const int inf=0x3f3f3f3f;
const i64 INF=0x3f3f3f3f3f3f3f3f;
const int N=2e5+5;
i64 n,d,x[N];
bool vis[N];
vector<int> mp[N];
int check(int p,int q){
	memset(vis,false,sizeof(vis));
	int cnt=0;
	queue<int> que;
	que.push(p);
	while(que.size()){
		int u=que.front();
		que.pop();
		for(auto v:mp[u]){
			if(v==q){
				cnt++;
			}
			if(vis[v]) continue;
			vis[v]=true;
			que.push(v);
		}
	}
	return cnt;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d){
				mp[i].push_back(j);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			if(check(i,j)==2){
				ans++;	
			}
		}
	}
	cout<<ans<<"\n";
} 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c;
	cin>>c;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
