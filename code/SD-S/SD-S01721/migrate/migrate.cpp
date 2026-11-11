#include<bits/stdc++.h>
using namespace std;
long long a[500005],t,n,c,d,da,ji;
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
	cin>>n>>d;
	for(int j=1;j<=n;j++)
	cin>>a[j];
	da=d/(a[2]-a[1]);
	if(2*da>n-1)
	cout<<0<<endl;
	else cout<<n-2*da+1<<endl;
	}
	return 0;
} 
