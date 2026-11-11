#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n[t+5],k[t+5];
	for(int i=1;i<=t;i++){
		cin>>n[i]>>k[i];
		int u[n[i]+4],v[n[i]+4];
		for(int j=1;j<=n[i]-1;j++){
			cin>>u[j]>>v[j];
		}
	}
	return 0;
}
