#include<bits/stdc++.h>
using namespace std;
int u[1000005],v[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			cin>>u[i]>>v[i];
		}	
	}
	return 0;
}
