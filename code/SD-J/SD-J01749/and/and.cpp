#include<bits/stdc++.h>
using namespace std;
int x[200005];
int dp[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}
	if(m==1){
		sort(x+1,x+n+1,greater<int>());
		cout<<x[1];
		return 0;
	}
	if(m==n){
		int ss=x[1];
		for(int i=2;i<=n;i++){
			ss=ss&x[i];
		}
		cout<<ss;
		return 0;
	} 
	if(m==2&&n<=20000){
		int ss=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ss=max(ss,x[i]&x[j]);
				}
			}
		}
		cout<<ss;
		return 0;
	}
	dp[1]=x[1];
	dp[0]=int(pow(2,31))-1;
	for(int i=2;i<=m;i++){
		dp[i]=0;
	} 
	for(int i=2;i<=n;i++){
		for(int j=m;j>=1;j--){
			dp[j]=max(dp[j],dp[j-1]&x[i]);
		}
	}
	cout<<dp[m];
	return 0;
}//×¢Òâm n 
