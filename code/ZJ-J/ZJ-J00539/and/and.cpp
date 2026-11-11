#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,m,a[N],b[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	ll ans=0;
	for(int i=29;i>=0;--i){
		ll cnt=0;
		for(int j=1;j<=n;++j) if(a[j]&(1<<i)) b[++cnt]=a[j];
		if(cnt>=m){
			ans+=(1<<i);n=cnt;
			for(int j=1;j<=n;++j) a[j]=b[j];
		}
	}
	cout<<ans;
	return 0;
}
