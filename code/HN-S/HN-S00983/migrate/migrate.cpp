#include<bits/stdc++.h>
using namespace std;
int op,t;
int n,k;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>op>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<n*2<<"\n"; 
	}
	return 0;
}

