#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		long long d;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		if(n<=2)cout<<0<<endl;
		if(n<=2)continue; 
		long long len=a[2]-a[1];
		if(d<2*len){
			cout<<0<<endl;//只能飞一下 或者 飞不了 
			continue;
		}
		cout<<max(1ll*0,n-2*(d/len)+1)<<endl;
	}
	return 0;
}
