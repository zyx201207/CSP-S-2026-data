#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ans;
ll m,a[500010],sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,greater<int>());
	sum=m;
	for(int i=1,j=1;i<=n;i++){
		while(j<=n&&sum>=a[i]-a[j])sum-=a[i]-a[j],j++;
		ans=max(ans,j-i);
		sum+=(j-i-1)*1ll*(a[i]-a[i+1]);
	}
	cout<<ans;
	return 0;
}
