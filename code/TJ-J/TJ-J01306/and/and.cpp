#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int n,m;
int a[N];
/*
pre:100+85+60=245
j考啥样啥样吧基本一直在复习s的 
没办法yh学校实在太卷了初三还要中考
我想北京了qwq
高一再战罢我要先退役了
中考加油了 18题我爱你 
*/
int dp[2005][2005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ll ans=0;
	ll mn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=(ans==0?a[i]:ans&a[i]);
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i==1)dp[1][1]=a[1];
		else dp[i][1]=max(dp[i-1][1],a[i]);
	}
	if(m==1)cout<<a[n];//6
	else if(m==n)cout<<ans;//7 sixseven
	else if(m==n-1){//11 12
		ans=0;
		for(int i=2;i<=n;i++)ans=(ans==0?a[i]:ans&a[i]);
		cout<<ans;
	}else if(m==2){//8 9 10
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				mn=max((ll)(a[i]&a[j]),mn);
			}
		}
		cout<<mn;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=2;j<=m;j++){
				dp[i][j]=dp[i-1][j-1]&a[i];
			}
		}
		cout<<dp[n][m];
	}
//4 2
//3 15 12 12
return 0;
}

