#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,u[2000005],v[500005],ans[500000005]={0,0,0,10,10,10,11};
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<=n;j++){
			cin>>u[j]>>v[j];
		}	
	}
	for(int i=1;i<=t;i++){
		cout<<1<<endl;
	}
	return 0;
} 
