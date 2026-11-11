#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t; 
int n,d;
int a[2000005];
int res,cnt;
void dfs(int u,int v,int w){
	if(u==v){
		if(w==res) cnt++;
		if(w<res){
			res=w;
			cnt=1;
		}
		return;
	}
	for(int i=u+1;i<=n;i++){
		if(a[i]-a[u]<=d&&i<=v){
			dfs(i,v,w+1);
			//cout<<"dfs "<<i<<" "<<w+1<<'\n';
		}
		else break;
	}
}
void work(){
	cin>>n>>d;
	int ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			res=LLONG_MAX,cnt=0;
			dfs(i,j,0);
			if(cnt==2){
				ans++;
				//cout<<i<<" "<<j<<'\n';
			}
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) work();
	return 0;
}
