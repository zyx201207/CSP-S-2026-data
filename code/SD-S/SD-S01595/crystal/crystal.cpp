#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1,l=1,sum=0;i<=n;i++){
		while(sum>m)sum-=a[i]-a[l],l++;
		ans=max(ans,i-l+1);
		sum+=(a[i+1]-a[i])*(i-l+1);
	}
	cout<<ans;
}
