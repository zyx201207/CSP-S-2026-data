#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+10;
ll a[N],s[N];
int dp[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=0;
	ll m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i++) s[i]=s[i-1]+a[i];
	dp[1]=1;
	for(int i = 2,j = 1;i <= n;i++){
		int t = (i-j)*a[i]-(s[i-1]-s[j-1]);
		while(t > m){
			j++;
			t = (i-j)*a[i]-(s[i-1]-s[j-1]);
		}
		dp[i]=i-j+1;
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}