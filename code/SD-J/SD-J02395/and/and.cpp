#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+20;
ll n,a[N],m,b[N]; 
bool cmp(ll x,ll y){
	return x>y; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	bool flag=0;
	for(ll k=30;k>=0;k--){
		ll cnt=0; 
		for(ll i=1;i<=n;i++){
			if(((a[i]>>k)&1)==1){
				cnt++;
				b[cnt]=a[i];
			}
		}
		if(cnt>m){
			for(ll i=1;i<=cnt;i++){
				a[i]=b[i];
			}
			n=cnt;
		}
		else if(cnt==m){
			ll ans=b[1];
			for(ll i=2;i<=cnt;i++){
				ans&=b[i];
			}
			cout<<ans;
			flag=1;
			break;
		}
		else{
			for(ll i=1;i<=n;i++){
				if(((a[i]>>k)&1)==1) a[i]-=(1<<k);
			}
			sort(a+1,a+1+n,cmp);
		}
	}
	ll ans=a[1];
	for(ll i=2;i<=m;i++){
		ans&=a[i];
	}
	if(!flag) cout<<ans;
	return 0;
}
//Trick||Treat!
