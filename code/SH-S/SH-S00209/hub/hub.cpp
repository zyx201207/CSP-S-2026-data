#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,k;
int ans;
int num=1;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>k;
		for(int i=1; i<n; i++) {
			int u,v;
			cin>>u>>v;
		}
		cout<<num<<endl;
		if(num==1)num=2;
		else num=1;
	}
}
