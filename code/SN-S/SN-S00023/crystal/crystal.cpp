#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,a[500010],d[500010];
int n,ans;
bool check(ll x,ll pos){
	ll cost=d[pos]-d[x]-x*(a[pos]-a[x]);
	if (cost>m) return false;
	return true;
}
int solve(int i){
	int l=1,r=i,pos=r;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid,i)){
			pos=mid;
			r=mid-1;
		}
		else {
			l=mid+1;
		}
	}
	return i-pos+1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) d[i]=a[i]-a[i-1];
	for (int i=1;i<=n;i++) d[i]=d[i-1]+d[i]*i;
	for (int i=1;i<=n;i++) ans=max(ans,solve(i));
	cout<<ans;
	return 0;
} 
