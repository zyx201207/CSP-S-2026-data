#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n,m,a[500005],d,ans,c,T;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
//		cout<<T<<" "<<n<<" "<<d<<"\n";
		bool flag=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])flag=1;
		}
		if(!flag){
			if(d>=a[3]-a[2])
			cout<<max((n-3)*(n-2)/2,0LL)<<"\n";
			else cout<<"0\n";
		}
	}
	return 0;
}
