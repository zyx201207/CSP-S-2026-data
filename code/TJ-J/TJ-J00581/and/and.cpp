#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,m;
long long a[MAXN];
long long dp[MAXN];
long long maxa=INT_MIN;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	dp[1]=maxa;
	for(int i=1;i<=n;i++){
		for(int j=m;j>1;j--){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m]<<endl;
	return 0;
}
