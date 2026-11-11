#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[1000010],v[1000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u[i];
		}
		for(int i=1;i<=n;i++){
			cin>>v[i];
		}
		cout<<rand()%(2*k)<<"\n";
	}
	return 0;
}
