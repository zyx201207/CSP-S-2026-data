#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n;
ll m;
ll b[N];
ll dp[N];
ll cst[N];
ll ans;


int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>b[i];
	}
	sort(b+1,b+1+n);
	dp[1]=1;
	cst[1]=0;
	int l=1;
	for(int i=2; i<=n; i++) {
		dp[i]=dp[i-1]+1;
		cst[i]=cst[i-1]+dp[i-1]*(b[i]-b[i-1]);
		while(cst[i]>m) {
			cst[i]-=(b[i]-b[l]);
			l++;
			dp[i]--;
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
