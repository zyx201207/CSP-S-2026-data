#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--){
		cin>>n;
		cout<<n-1<<'\n';
		for(int i=1;i<=n+1;i++){
			cin>>n;
		}
	} 
	return 0;
}
