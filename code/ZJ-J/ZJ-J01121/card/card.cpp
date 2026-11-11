#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500010,M=300010;
ll n,m,i,dp[N],j,ans[M],a[N],cs[N],sum;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i],cs[a[i]]++;
	sum=0;
	for(i=1;i<=n;i++){
		dp[i]=i-(sum-ans[a[i]]);
		cs[a[i]]--;
		sum=sum-ans[a[i]];
		if(cs[a[i]]>0)sum=sum+dp[i];
		ans[a[i]]=dp[i];
	}
	for(i=1;i<m;i++)cout<<ans[i]<<" ";
	cout<<ans[m];
	return 0;
}

