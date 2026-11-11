#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,ans;
ll a[500005],m;
void twopoints(){
	int j=1;
	ll sum=0;
	for(int i=1;i<=n;++i){
		ll diff=a[i]-a[i-1];
		sum+=(i-j)*diff;
		while(j<=i&&sum>m){
			sum-=(a[i]-a[j]);
			j++;
		}
		ans=max(ans,i-j+1);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	twopoints();
	cout<<ans;
	return 0;
}
