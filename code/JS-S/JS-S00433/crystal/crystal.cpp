/*


FREOPEN!!!!!!


*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF=0x3f3f3f3f;
const int MX=500005;

ll n,m;
ll a[MX];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(n==1){
		cout<<1;
		return 0;
	}
	
	sort(a,a+n+1);
	//cout<<m;

	ll res=-1;
	for(int i=2;i<=n;i++){
		ll M=m;
		ll ans=0;
		for(int j=i-1;j>=1;j--){
			ll k=a[i]-a[j];
			
			if(M>=k){
				M-=k;
				ans++;
				//cout<<"+1";
			}
		}
		res=max(res,ans);

	}
	
	cout<<res+1;
	return 0;
}
