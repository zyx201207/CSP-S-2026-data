#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int dp[200005];
long long n,m,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ans=a[n];
	for(int i=n-1;i>n-m;i--){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}


