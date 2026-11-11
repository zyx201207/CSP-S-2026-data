#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(long long i=1;i<=n;i++) cin>>a[i];
		long long tt=a[2]-a[1];
		if(d<=a[2]-a[1]){
			cout<<0<<'\n';
		}else{
			cout<<max(n-(d/tt*2)+1,0ll)<<'\n';
		}
	}
	return 0;
}