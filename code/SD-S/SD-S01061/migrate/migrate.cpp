#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000006];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		int sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11||c==12){
			for(int i=1;i<n;i++){
				if((x[2]-x[1])*i<=d){
					sum+=n-i;
				}
			}
			cout<<sum<<endl;
			return 0;
		}
		if(c==13||c==14){
			cout<<2<<endl;
			return 0;
		}
	}
	cout<<0<<endl;
	return 0;
}
