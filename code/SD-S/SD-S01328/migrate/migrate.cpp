#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d;
		long long a[2000005];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long q=a[2]-a[1];
		if(q>d) cout<<0<"\n";
		cout<<n-d-1<<"\n";
	}
	return 0;
} 
