#include <bits/stdc++.h>
using namespace std;

int c,t,n,k;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","W",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
		cout<<n%k;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
