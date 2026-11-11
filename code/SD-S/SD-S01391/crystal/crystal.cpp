#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
ll n,m,a[500011],ans;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1,pd=1,sum=0; i<=n; i++) {
		sum+=(a[i]-a[i-1])*(i-pd);
		while(pd<i&&sum>m)sum-=a[i]-a[pd],pd++;
		ans=max(ans,i-pd+1);
	}
	cout<<ans<<endl;
	return 0;
}
