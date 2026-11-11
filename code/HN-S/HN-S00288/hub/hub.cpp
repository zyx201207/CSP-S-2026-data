#include<bits/stdc++.h>
using namespace std;
int u[800001],v[800001];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int n,k,tmp;cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>u[i]>>v[i];
		}
		if(k==n){
			cout<<0<<endl;
			continue;
		}
		if((n-1)>>1<=k) {
			cout<<1<<endl;
			continue;
		}
		tmp=(n+1)>>1;
		cout<<(tmp-k)/4+1;
	}
	return 0;
}
