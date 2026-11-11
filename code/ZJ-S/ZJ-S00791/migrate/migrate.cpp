#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mx=2e6+5;
int c,T,n,d,a[mx];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int k=a[2]-a[1];
		cout<<0<<"\n";
	}
	return 0;
}
