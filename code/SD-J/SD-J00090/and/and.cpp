#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
vector<ll>a;
const ll N=25;
ll dp[N][N];
ll n,m;
ll dfs(ll i,ll cnt){
	if(cnt==0) return a[i];
	if(dp[i][cnt]!=-1) return dp[i][cnt];
	ll ans=0;
	for(int j=i+1;j<=n;j++){
		ans=max((dfs(j,cnt-1)&a[i]),ans);
	}
	return dp[i][cnt]=ans;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=-1;
		}
	}
	a.resize(n+1);
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1) flag=1;
	}
	sort(a.begin(),a.end());
	if(m==1){
		cout<<a[n]<<endl;
		return 0;
	}
	if(m==2){
		ll maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx<<endl;
		return 0;
	}
	if(m==n){
		ll ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans<<endl;
		return 0;
	}
	if(n<=20){
		ll ans=0;
		for(int i=1;i<=n-m+1;i++){
			ans=max(ans,dfs(i,m-1));
		}
		cout<<ans<<endl;
		return 0;
	}
	if(flag==0){
		cout<<n-m<<endl;
		return 0;
	}
	cout<<a[n-m+1]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


