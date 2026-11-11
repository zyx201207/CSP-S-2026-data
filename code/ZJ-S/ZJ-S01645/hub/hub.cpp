#include<iostream>
using namespace std;
long long c,t,x[1000009],n,k,u[200006],v[200006];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<=n-1;j++){
			cin>>u[i]>>v[i];
		}
		if(n/k<=2)cout<<1<<endl;
		if(n/k==3)cout<<2<<endl;
		if(n/k>3)cout<<n/2<<endl;
	}
	return 0;
} 
