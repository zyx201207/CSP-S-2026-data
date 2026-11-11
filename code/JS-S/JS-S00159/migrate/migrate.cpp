#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		if(n<=3){
			cout<<0<<endl;
			return 0;
		}
		else cout<<n/2<<endl;
	}
	return 0;
}
