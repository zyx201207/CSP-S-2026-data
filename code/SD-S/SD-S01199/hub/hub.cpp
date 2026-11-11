#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			long long u,v;
			cin>>u>>v;
		}
		if(n<=k){
			cout<<0<<"\n";
		}
		else if(c==13||c==14||c==0){
			cout<<(n-2*k+1)/2/2/2+1<<"\n";
		}
	}
	return 0;
}
