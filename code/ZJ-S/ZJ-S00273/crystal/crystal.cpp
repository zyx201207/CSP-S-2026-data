#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,t,ans,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l=1;
	for(int i=2;i<=n;i++){
		t+=(i-l)*(a[i]-a[i-1]);
		while(t>m){
			t-=(a[i]-a[l]);
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
