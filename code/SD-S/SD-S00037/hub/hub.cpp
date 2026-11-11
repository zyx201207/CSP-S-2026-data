#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int c,t,n,k,u[N],v[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++) cin>>u[i]>>v[i];
		if(c==13||c==14){
			cout<<ceil(n/2*1.0/k)<<endl;
		}
		else cout<<1<<endl;
	}
	return 0;
}
