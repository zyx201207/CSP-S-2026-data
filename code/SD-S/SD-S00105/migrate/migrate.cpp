#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d;
int x[2000005];
pair<int,int> dfs(int u,int v){
	if(u==v)return {0,1};
	int ans=v-u+100,sum=-1;
	for(int i=u+1;i<=v;i++){
		if(x[i]-x[u]>d)break;
		auto t=dfs(i,v);
		if(t.second==-1)continue;
		if(t.first+1<ans){
			ans=t.first+1;
			sum=t.second;
		}else if(t.first+1==ans){
			sum+=t.second;
		}
	}
	if(sum>2)return {0,-1};
	return {ans,sum};
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	int cnt=0;
	for(int u=1;u<=n;u++){
		for(int v=u+1;v<=n;v++){
			if(dfs(u,v).second==2){
				cnt++;
			}
		}
	}
	cout<<cnt<<"\n";
}
signed main(){

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>c>>t;
	
	while(t--){
		solve();
	}

	return 0;
}

