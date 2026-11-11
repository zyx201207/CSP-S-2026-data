#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+9;
int op,t,a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>op>>t;
	while(t--){
		int x,y;
		for(int i=1;i<=x;i++) cin>>a[i];
		if(op==11||op==12){
			int z=y/a[1];
			if(x%z==0) cout<<0<<'\n';
			else cout<<x/z+1<<'\n';
		}
		else cout<<1<<'\n';
	}
	return 0;
}
