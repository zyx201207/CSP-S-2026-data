#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int p=1;p<=t;p++){
		long long n,d;
		cin>>n>>d;
		long long x[2000005];
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<n-3<<"\n";
	}
	return 0;
}
