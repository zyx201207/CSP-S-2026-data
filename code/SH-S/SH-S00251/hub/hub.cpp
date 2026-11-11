#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	while(cin>>c>>t){
		while(t--){
			double n,k;
			cin>>n>>k;
			for(int i=1;i<=n-1;i++){
				int u,v;
				cin>>u>>v;
			}
			if(n==k){
				cout<<"0"<<endl;
				continue;
			}
			cout<<ceil(((n-1.0)/2.0-k+4.0)/4.0)<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
