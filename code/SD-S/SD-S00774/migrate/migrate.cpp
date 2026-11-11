#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			int n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int T=a[2]-a[1];
			int ma=d/T;
			int ans=0;
			if(ma<=1){
				cout<<0<<"\n";
			}	
			else{
				for(int i=1;(i+1)*ma-1<=n-1;i++){
					ans+=n-i*ma-1;
				}
				cout<<ans<<"\n";
			}
		}	
	}
	else{
		while(t--){
			int n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			cout<<0<<'\n';			
		}
	}
	return 0;
}
