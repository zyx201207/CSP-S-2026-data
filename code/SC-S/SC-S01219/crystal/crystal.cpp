#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],m;int n;
void solve(){
	cin >> n >> m;
	for (int i=1;i<=n;++i) cin >> a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=n;++i) a[i]=a[i-1]+a[i];
	int ans=0;
	for (int i=1,lt,rt,mid;i<=n;++i){
		lt=1,rt=i;
		while (lt<rt){
			mid=(lt+rt)>>1;
			if ((a[i]-a[i-1])*(i-mid+1)-(a[i]-a[mid-1])<=m){
				rt=mid;
			}else{
				lt=mid+1;
			}
		}
		ans=max(ans,i-lt+1);
//		cout<<i<<" "<<lt<<'\n';
//		cout<<a[i]-a[i-1]<<" ";
	}
//	cout<<a[3]*(3-1+1)-(a[3]-a[1-1])<<"\n";
//	cout<<"\n";
	cout<<ans<<"\n";
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T=1;
//	cin >> T;
	for (int _=0;_<T;++_) solve();
	cout.flush();
	return 0;
}
//14:40