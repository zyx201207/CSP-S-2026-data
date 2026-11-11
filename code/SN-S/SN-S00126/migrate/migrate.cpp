#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t,n,d,a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int t=a[2]-a[1];
		if(t>d) cout<<0<<"\n";
		else{
			if(t==d) cout<<n-3<<"\n";
			else {
				int g;
				if(d%t==0) g=d/t+2;
				else if(d/t==1) cout<<0<<'\n';
				else g=d/t+3;
				cout<<max(0,n-g+1)<<"\n";
			}
		} 
	} 
	return 0;
}
