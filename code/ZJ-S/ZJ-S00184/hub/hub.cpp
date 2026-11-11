#include <bits/stdc++.h>
using namespace std;
int c,T,n,k,u,v;
vector<int> vec[100005];
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--) {
		cin>>n>>k;
		for(int i=0; i<n-1; i++) {
			cin>>u>>v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		int a=(n-k)/3;
		cout<<(a==0 ? 1 : a)<<endl;
	}
	return 0;
}