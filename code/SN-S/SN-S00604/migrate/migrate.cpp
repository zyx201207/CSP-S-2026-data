#include<bits/stdc++.h>
using namespace std;
const int N=2e6+6;
long long q,n,d,a[N],c;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>q;
	while(q--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		d=d/(a[2]-a[1]);
		cout<<max(n-2ll*d+1ll,0ll)<<endl;
	}		
	return 0;
}
