#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+9;
ll n,m,a[N],ans,sum,t;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		sum+=t*(a[i]-a[i-1]);
		while(sum>m && t>0){
			t--;
			sum-=(a[i]-a[i-t]);
		}
		t++;
		ans=max(ans,t);
	}
	cout<<ans;
	return 0;
}
