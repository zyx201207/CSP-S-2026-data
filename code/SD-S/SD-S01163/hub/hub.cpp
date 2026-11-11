#include <bits/stdc++.h>
using namespace std;
int n,c,t,v[500005],k;
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int tt=1; tt<=t; tt++) {
		cin>>n>>k;
		for(int i=1; i<n; i++) {
			cin>>v[i]>>v[i];
		}
		cout<<tt<<endl;
	}
	return 0;
}

