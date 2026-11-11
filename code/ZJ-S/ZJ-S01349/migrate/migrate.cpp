#include<bits/stdc++.h>
using namespace std;
long long ccc,t,n,a[2114514],d,b[2114514],c[2114514];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>ccc>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		long long x=d/(a[2]-a[1]);
		if(x==0 || x==1) cout<<0<<'\n';
		else cout<<max(n-(x*2)+1,0ll)<<'\n';
	}
	return 0;
}
