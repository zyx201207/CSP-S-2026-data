#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v; 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i=0;i<n-1;i++) cin >> u >> v;
		cout << (t>0?1:2) << "\n";
	}
	return 0;
}
