#include<bits/stdc++.h> 
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int x[n+5];
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(x[j]-x[i]>=3&&x[j]-x[i]<=2*d-1) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
