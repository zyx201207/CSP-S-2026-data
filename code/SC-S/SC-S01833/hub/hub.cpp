#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int c;
ll t;
int n,k;
int u,v;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0);
	
	cin >> c >> t;
	while (t --){
		cin >> n >> k;
		for (int i = 1;i <= n-1;i ++)
			cin >> u >> v;
	}
	
	return 0;
}