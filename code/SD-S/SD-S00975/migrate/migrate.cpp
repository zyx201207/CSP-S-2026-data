#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e6+10;
const ll inf=1e12;
ll n,d;
ll x[N];
ll dp[N][2]; 
ll sm[N];
int mian(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
//		dp[i][0]=inf;dp[i][1]=0;
	}
	if(n==1){
		cout<<0<<'\n';
		return 0;
	}
	ll ans=0;
	for(int l=1;l<=n;l++){
		dp[l][0]=0;dp[l][1]=1;
		ll j=l,j2=l;
		sm[l]=1;
		for(int i=l+1;i<=n;i++){
			dp[i][0]=inf;dp[i][1]=0;
			while(x[i]-x[j]>d){
				j++;
			}
			dp[i][0]=dp[j][0]+1;
			if(dp[i][0]>=inf) break;
			while(dp[j][0]>=dp[j2][0]){
				j2++;
			}
			
			dp[i][1]=sm[j2-1];
			if(j-1>=l) dp[i][1]-=sm[j-1];
			sm[i]=sm[i-1]+dp[i][1];
			if(dp[i][1]==2){
				ans++;	
			}
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}
int mian2(){
	cin>>n>>d;

	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(n==1){
		cout<<0<<'\n';
		return 0;
	}
	ll d2=x[2]-x[1];
	ll tmp=d/d2;
	if(tmp==0||tmp==1){
		cout<<"0\n";
		return 0;
	}
	ll l=tmp*2-1;
	ll ans=max(0ll,n-l);
	cout<<ans<<'\n';
	return 0;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t; 
	while(t--){
		
		if(c==11||c==12){
			mian2();
		}
		else{
			mian();
		}
	} 
	return 0;
}
/*
先来猜几个性质吧，说不定能做

应该是动规/数据结构

“最短”很重要

大概需要关心每个点最远飞到哪里，这个是不减的

不到终点的鸟大概率会飞到最远 

首先到每个岛的路程如果有意义一定非0 且整数 

然后既然是2，则需要转移过来它的两个点 dp 值为{1,1}或2

也就是这个点最多由最短路径与它相同的两个点到达 

这个能做吗 

区间左端点是知道的  区间右端点怎么做 
*/
