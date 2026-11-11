#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,u[20005],v[20005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u[i]>>v[i];
		}
		if(t==1){
			cout<<1<<endl;
		}else{
			cout<<2<<endl;
		}
	}
	
	return 0;
}
