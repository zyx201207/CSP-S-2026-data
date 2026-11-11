#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d,a,b,c;
		cin>>n>>d;
		cin>>a>>b;
		for(int j=2;j<n;j++){
			scanf("%lld",&c);
		}
		if(d<2*(b-a)){
			cout<<0<<endl;
		}else{
			cout<<n-d/(b-a)<<endl;
		}
	}
	return 0;
}