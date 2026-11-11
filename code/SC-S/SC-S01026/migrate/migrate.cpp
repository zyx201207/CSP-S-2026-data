#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
#define ll long long
ll c,t,n,d,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
//		cout<<n<<' '<<d<<' ';
		for(int i=1;i<=n;i++) cin>>a[i];
		ll t=d%int(abs(a[2]-a[1])),ti=d/int(abs(a[2]-a[1]));
//		cout<<t<<' ';
		if(t==1||t>n) cout<<0<<endl;
		else cout<<n-ti*2+1<<endl;
	}
	return 0;
} 