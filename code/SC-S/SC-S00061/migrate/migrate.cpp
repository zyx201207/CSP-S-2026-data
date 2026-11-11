#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		long long n,d,x[100001];
		cin>>n>>d;
		for(long long i=0;i<n;i++){
			cin>>x[i];
		}
		cout<<n/2-t<<"\n";
	}
	
	return 0;
}