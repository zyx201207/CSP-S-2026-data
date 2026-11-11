#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	ll ans=0,cnt=0;
	for(int i=2;i<=n;++i){
		++cnt;
		m-=cnt*(a[i]-a[i-1]);
		if(m<0){
			cnt-=1;
			m+=a[i]-a[i-cnt];
		}
		ans=max(ans,cnt);
	}
	printf("%lld",ans+1);
	return 0;
}

