#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N=2e6+5;
LL n,d;int a[N];
void solve(){
	cin>>n>>d;LL ans=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=4;i<=n;i+=2){
		ans+=n-i+1;
	}cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--) solve();
	return 0;
}
