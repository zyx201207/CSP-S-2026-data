#include<bits/stdc++.h>
using namespace std;
const long long N=1e2+5;
int c,t,n[N],k[N],u[N],v[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i]>>k[i];
		cin>>u[i]>>v[i];
	}
	for(int i=1;i<=t;i++){
		cout<<n[i]-v[i]<<endl;
	}
	return 0;
}