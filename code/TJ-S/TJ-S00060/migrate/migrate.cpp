#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<=(d*2-1)){
			cout<<0<<endl;
		}
		else{
			cout<<n-(d*2-1)<<endl;
		}	
	}
	return 0;
}
