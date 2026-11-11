#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll a[N],dp[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i]=a[i];
	}
	dp[0]=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--){
			dp[i]=max(dp[i],(dp[j-1]&a[i])); 
		}
	}
	cout<<dp[m];
	return 0;
}

