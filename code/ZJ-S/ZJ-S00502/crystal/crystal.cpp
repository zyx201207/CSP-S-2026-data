#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const int N = 500005;

ll a[N], pre[N];
int n;
ll m;
bool check(int x){
	for(int i=x;i<=n;i++){
		int r = i;
		int l = r - x + 1;
		if(1ll*a[i]*(r-l+1)-pre[r]+pre[l-1]<=m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i] = pre[i-1] + a[i];
	int L=1,R=n, ans=0;
	while(L<=R){
		int mid=(L+R)>>1;
		if(check(mid)){
			ans=mid;
			L=mid+1;
		}else{
			R=mid-1;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
