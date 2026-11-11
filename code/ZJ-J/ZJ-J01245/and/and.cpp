#include<bits/stdc++.h>
using namespace std;
long long a[200010];
string b[200010];
long long dp[200010];

int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		b[i]=jinzhi(a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			dp[j]=max(dp[j],dp[j-1]|a[i]);
		}
	}
	cout << dp[m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}