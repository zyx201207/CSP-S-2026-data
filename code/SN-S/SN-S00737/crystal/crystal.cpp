#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[512345],l,r,mid,ans;
int dp[512345][21];
int num(int x,int y){
	int cnt=0;
	for(int t=21;t>=0;t--){
		if(x+((1ll<<t)-1)<=y){
			cnt+=dp[x][t];
			x+=(1ll<<t);
		}
	}
	return cnt;
}
bool f(){
	int cnt=9e18;
	for(int i=1;i<=n-mid+1;i++){
		cnt=min(cnt,a[i+mid-1]*mid-num(i,i+mid-1));
	}
	return cnt<=m;
}
void Q_Q(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) dp[i][0]=a[i];//这行代码查了半小时 
	for(int j=1;j<=20;j++){
		for(int i=1;i<=n-(1ll<<(j-1ll));i++){
			dp[i][j]=dp[i][j-1]+dp[i+(1ll<<(j-1ll))][j-1];
//			cout<<dp[i][j]<<" ";
		}
//		cout<<endl;
	}
	l=1,r=n;
	while(l<=r){
//		printf("%lld %lld %lld\n",l,mid,r);
		mid=(l+r)/2;
		if(f()){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	Q_Q();
} 
/*
哈哈哈，四个样例全过了
今天我就要成了
*/ 
