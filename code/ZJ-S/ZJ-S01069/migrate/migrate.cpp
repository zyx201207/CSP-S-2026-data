#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,ans;
long long a[200005],m[10001],x[200005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t>>n>>d;
	ans=t*d*d/n;
	cout<<ans<<endl;
	cout<<ans-c;
	return 0;
}
