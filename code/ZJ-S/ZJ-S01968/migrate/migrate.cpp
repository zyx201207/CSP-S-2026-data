#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+7;
const int INF=1e18+9;
int c,t,n,d,a[N];
vector<int> dp[5001];//表示从x出发到j的方案数量,花费了多少步数 
int ans;
void solve(int x){
	for(int i=1;i<=n;i++){
		dp[i].clear();
	}
	dp[x].push_back(0);
	for(int i=x+1;i<=n;i++){
		for(int j=1;a[i]-a[i-j]<=d and i-j>=x;j++){
			for(auto k:dp[i-j]){
				dp[i].push_back(k+1);
			}
		}
	}
	for(int i=x+1;i<=n;i++){
		int minl=INF;
		for(auto f:dp[i]){
			minl=min(minl,f);
		}
		int sum=0;
		for(auto f:dp[i]){
			if(f==minl) sum+=1;
		}
		if(sum==2){
			ans++;
		}
	}
}
void solve2(){
	int cha=a[2]-a[1];
	int flyy=d/cha;
	if(d<cha){
		cout<<0<<endl;
		return;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(i+2*flyy<=n){
			if((flyy-1)%2==0) ans+=(flyy-1)/2;
			else ans+=(flyy-1)/2+1;
		}
		else {
			if((n-i)-flyy>0){
				if((n-i)-flyy%2==0) ans+=((n-i)-flyy)/2;
				else ans+=(n-i-flyy)/2+1;
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11 or c==12){
			solve2();
			continue;
		}
		for(int i=1;i<=n-1;i++){
			solve(i);
		} 
		cout<<ans<<endl;
		ans=0;
	}
	
	return 0;
}
