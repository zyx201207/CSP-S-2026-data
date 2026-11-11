#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int n,m;
int dp[N][N];
int a[N];
bool check(int x){
	int cnt=0;
	while(x){
		cnt+=x%2;
		x/=2;
		cnt--;
	}
	return cnt==0;
}
int mx;
bool flag;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!check(a[i]))flag=true;
		mx=max(mx,a[i]);
	}
	if(!flag){
		cout<<mx;
		return 0;
	}
	if(m==n){
		for(int i=2;i<=n;i++)a[1]&=a[i];
		cout<<a[1];
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)dp[i][1]=max(dp[i][1],a[j]);
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++)dp[i][j]=max(dp[i-1][j],(dp[i-1][j-1]&a[i]));
	}
	cout<<dp[n][m];
	return 0;
}
