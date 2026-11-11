#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main(){
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	cin >> c >> t;
	for(int tn=0; tn<t; tn++){
		cin >> n >> k;
		int ans=0,ua=0,va=0;
		for(int i=1; i<n; i++){
			int u,v;
			cin >> u >> v;
			ua+=u/v;
			va+=u*v/4;
		}
		ans += ua/4+va/5;
		cout << ans << endl;
	}
}
