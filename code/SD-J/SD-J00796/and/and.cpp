#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int N = 2e5;
int n,m,a[N],dp[N],mx,inf;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	inf=pow(2,30);
	inf--;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	dp[0]=inf;
	for(int i = 1;i <= n;i++){
		for(int j = i;j > 0;j--){
			dp[j]=max((dp[j-1]&a[i]),dp[j]);
		}
		mx=max(mx,dp[m]);
	} 
	cout<<mx;
	return 0;
}
