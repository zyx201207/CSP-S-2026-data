#include<bits/stdc++.h>
using namespace std;
long long c,t,a[2000006]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(d==1){
			cout<<0<<endl;
			continue;
		}
		else{
			cout<<n-d-1<<endl;
		}
	}
	return 0;
}
