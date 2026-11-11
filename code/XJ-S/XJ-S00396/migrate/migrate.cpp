#include<bits/stdc++.h>
using namespace std;
int a[500010];
int n,m,mn=0x3f3f3f;
priority_queue<int,vector<int>,greater<int> >ans;
void dfs(int x,int y,int sum){
	if(x==y){
		mn=min(mn,sum);
		if(sum>mn)return;
		ans.push(sum);
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]<=m){
			dfs(i,y,sum+1);
		}
	}
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			mn=0x3f3f3f;
			dfs(i,j,0);
			int i=ans.top(),cnt=0;
			while(ans.size()){
				if(i==ans.top()){
					cnt++;
					ans.pop();
				}else{
					ans.pop();
				}
			}
			if(cnt==2)sum++;
		}
	}
	cout<<sum<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,_;
	cin>>c>>_;
	while(_--){
		solve();
	} 
	return 0;
} 
