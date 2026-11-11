#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
		for(int i=1;i<=n;i+=2){
			if((i+2)*k>=n){
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
