#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int NM = 2e6,inf = 2e9;
ll X[NM+4];
ll d;
int n;
vector<int> dis(NM+4);
vector<int> A(NM+4);
void dfs(int x){
	for(int i = x+1;i <= n;i++){
		if(X[i]-X[x] > d) break;
		if(dis[i] > dis[x]+1) A[i] = 0;
		if(dis[i] == dis[x]+1) A[i]++;
//		if(i == 4) cout<<dis[i]<<' '<<dis[x]<<' '<<x<<"open\n";
		dis[i] = min(dis[x]+1,dis[i]);
		dfs(i);
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ans = 0;
		for(int i = 1;i <= n;i++) cin>>X[i];
		for(int k = 1;k <= n;k++){
			fill(dis.begin(),dis.begin()+n+1,inf);
			fill(A.begin(),A.begin()+n+1,0);
			dis[k] = 0,dfs(k);
			for(int i = k;i <= n;i++){
//				cout<<dis[i]<<' ';
//				cout<<'\n';
				if(A[i] == 1) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
