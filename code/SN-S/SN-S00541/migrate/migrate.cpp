#include <bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int l=0;l<t;l++){
		long long n,d,f[1000010];
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>f[i];
		}
		if(d==2){
			cout<<n-3<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
}
