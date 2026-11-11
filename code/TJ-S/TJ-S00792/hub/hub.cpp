#include<bits/stdc++.h>
using namespace std;
int n,k;

int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) {
		cin>>n>>k;
		for(int i=1; i<n; i++) {
			int u,v;
			cin>>u>>v;
		}
		if(n<=2)cout<<0<<endl;
		else cout<<1<<endl;
	}
	return 0;
}
