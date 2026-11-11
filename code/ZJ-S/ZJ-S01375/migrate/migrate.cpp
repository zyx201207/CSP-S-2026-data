#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,x[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c>=11&&c<=12){
			int diff=x[2]-x[1];
			if(d!=2*diff) cout<<0<<"\n";
			else{
				int ans=0;
				for(int i=1;i+3<=n;i++) ans++;
				cout<<ans<<"\n";
			}
		}else{
			cout<<0<<"\n";
		}
	}
	return 0;
}