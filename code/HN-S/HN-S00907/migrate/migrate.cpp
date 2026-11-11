#include<bits/stdc++.h>
using namespace std;

long long a[2000005];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long c,t;
	cin>>c>>t;
	for (long long i=1;i<=t;i++){
		long long n,d;
		cin>>n>>d;
		for (long long j=1;j<=n;j++){
			cin>>a[i];
		}
		if (d >= (a[2]-a[1])*2){
			cout<<d-3<<endl;
		}
	}
	return 0;
} 
