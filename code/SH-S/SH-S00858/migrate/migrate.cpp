#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int x[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int m=x[n]-x[n-1];
		if(d/m==1){
			cout<<"0"<<"\n";
			continue;
		}
		int xd=d/m;
		int ans=(n-2*xd)*xd;
		cout<<ans;
	}
	return 0;
}
