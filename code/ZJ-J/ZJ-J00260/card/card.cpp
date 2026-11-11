#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m;
ll a[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		if(a[1]==1&&a[n]==2){
			cout<<n<<" "<<n;
			return 0;
		}
		if(a[n]==1&&a[1]==2){
			cout<<n<<" "<<n;
			return 0;
		}
		if(a[1]==1&&a[n]==1){
			cout<<n<<" ";
			ll ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==2) ans++;
			}
			cout<<ans;
			return 0;
		}
		if(a[1]==2&&a[n]==2){
			ll ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
			cout<<ans<<" "<<n;
			return 0;
		}
		return 0;
	}
	for(int i=2;i<=n+1;i++){
		if(a[i]!=a[i-1]) cout<<i-1<<" ";
	}
	return 0;
}
