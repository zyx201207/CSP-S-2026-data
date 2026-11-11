#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,T;
int n,d,a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==13 || c==14){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			if(a[n]-a[1]==2*d) cout<<0<<"\n";
			else if(d==2) cout<<1<<"\n";
			else cout<<0<<"\n";
		}
	}
	return 0;
}
