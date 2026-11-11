#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x[2100000];
int main(){//chai
	////////   ////////        |             |
	//    //   //   //         |             |
	//  //     // //      =====+=====   =====+=====
	/////      ///             |             |
	//  //     //              |             |
	//    //   //              |             |
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	if(c>10){
		while(T--){
			int n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			cout<<0<<endl;
		}
		return 0;
	}
	while(T--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		sort(x+1,x+n+1);
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=n;j>=i+1;j--){
				if(x[j]-x[i]<d) break;
				if((x[j]-x[i])%d==0) continue;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}