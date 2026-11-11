#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
#define int long long
int c,t,n,d;
int a[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(c==0||c==11||c==12){
		int g=a[2]-a[1];
		if(g>=d&&2*g>d){
			cout<<0<<endl;
			return ;
		}
		cout<<n-(d/g+1)<<endl;
		return ;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
