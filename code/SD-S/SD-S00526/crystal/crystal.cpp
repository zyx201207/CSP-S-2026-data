#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define For(a,b,c) for(int i=a;i<=b;i+=c)
#define rep(a,b,c) for(int i=a;i>=b;i-=c)
const int N=5e5+5;
ll n, m, a[N], cha[N], ans=1;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) cha[i]=a[i]-a[i-1];
	for(ll l=2;l<n;){
		ll r=l, sum=cha[l], cnt=cha[l];
		while(sum<=m && r<=n){
			r++;
			sum+=(r-l+1)*cha[r];
			cnt+=cha[r];
		}
		ans=max(ans,r-l+1ll);
		while(sum>m){
			sum-=cnt;
			cnt-=cha[l++];
			if(l==n) break;
		}
	}
	cout << ans;
	return 0;
}
