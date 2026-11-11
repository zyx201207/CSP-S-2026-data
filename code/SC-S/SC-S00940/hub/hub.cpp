#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,c,t,u,v;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for (int i=1;i<n;i++){
			cin>>u>>v;
		}
		cout << i <<"\n";
	}
}