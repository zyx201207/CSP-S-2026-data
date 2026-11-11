#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
int c,t,n[N],k[N],u[N],v[N];
int main(){
freopen("hub.in","r",stdin);
freopen("hub.out","w",stdout);
cin>>c>>t;
for(int i=1;i<=t;i++){
	cin>>n[i]>>k[i];
	for(int j=1;j<=n[i];i++){
		cin>>u[i]>>v[i];
	}
}
cout<<u[1]<<endl<<v[1];
	return 0;
}

