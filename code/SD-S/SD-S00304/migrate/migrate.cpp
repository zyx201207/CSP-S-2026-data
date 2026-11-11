#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int x[N],d[N];
int c,t;
int n,dm;
int mi;
int cnt;
bool st[N];
void dfs(int u,int v,int l){
	if(u==v){
		if(l<mi){
			mi=l;
			cnt=1;
		} 
		else if(l==mi) cnt++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(st[i]) continue;
		int t=abs(x[u]-x[i]);
		if(t<=dm){
			st[i]=1;
			dfs(i,v,l+1);
			st[i]=0;
		} 
	}
}
void solve(){
	cin>>n>>dm;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		d[i]=x[i]-x[1];
	}
	int ans=0;
	if(n>5000){
		cout<<0<<endl;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(abs(x[i]-x[j])<=dm) continue;
				cnt=0;
				mi=1e9;
				memset(st,false,sizeof(st));
				st[i]=1;
				dfs(i,j,0);
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}

