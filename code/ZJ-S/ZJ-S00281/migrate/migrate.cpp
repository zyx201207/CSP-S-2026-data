#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll c,T;
ll a[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ll n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		ll k=d/(a[2]-a[1]);
		if(k==1||k==0){
			cout<<0<<"\n";
			continue;
		}
		if(n<=d){
			cout<<"0\n";
			continue;
		}
		cout<<max(n-(k*2-1),0ll)<<"\n";
	}
	return 0;
}
