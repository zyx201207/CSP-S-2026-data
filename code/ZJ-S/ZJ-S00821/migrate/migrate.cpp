#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
ll n,d;
ll ans=INT_MAX,sum=0;
ll a[2000010];
void dfs(int u,int v,int cnt){
	if(cnt>ans)return;
	if(u==v){
		if(cnt<ans){
			ans=cnt;
			sum=1;
		}
		else if(cnt==ans)sum++;
		return;
	}
	for(int i=u+1;i<=v;i++){
		if(a[i]-a[u]<=d)dfs(i,v,cnt+1);
		else break;
	}
	return;
}
int check(int ui,int vi){
	if(vi-ui<=d)return 0;
	sum=0;
	dfs(ui,vi,0);
	if(sum==2)return 1;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ll cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(check(i,j)){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}