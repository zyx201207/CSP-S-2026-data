#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[200010];
bool f[200010];
ll ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll bit=30;bit>=0;bit--){
		ll cnt=0;
		for(ll i=1;i<=n;i++){
			if(!f[i]&&(a[i]&(1ll<<bit)))cnt++;
		}
//		for(int i=1;i<=n;i++)cout<<f[i]<<' ';
//		cout<<endl;
//		cout<<bit<<' '<<cnt<<endl;
		if(cnt>=m){
			for(ll i=1;i<=n;i++){
				if((a[i]&(1ll<<bit))==0)f[i]=1;
			}
			ans+=(1ll<<bit);
		}
	}cout<<ans;
	return 0;
}