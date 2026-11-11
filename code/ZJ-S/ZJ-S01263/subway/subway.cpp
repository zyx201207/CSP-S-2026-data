#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q;
ll w[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;	
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	int a,b,t;
	cin >> a >> b >> t;
	while(q--){
		int u,v;
		cin >> u >> v;
		cout << w[u]+w[v]+4*t << endl; 
	}
	return 0 ;
}

