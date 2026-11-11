#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--){
		long long ans=0;
		cin>>n>>t;
		if (n%t==2) cout<<0<<endl;
		else{
			cout<<n/t+1<<endl;
		}
	}
	return 0;
}
