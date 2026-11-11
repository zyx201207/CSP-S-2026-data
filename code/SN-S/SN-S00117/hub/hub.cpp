#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	srand(time(0));
	for(int i=1;i<=t;i++){
		int n,k;
		cin >> n >> k;
		int u,v;
		for(int i=1;i<n;i++) cin >> u >> v;
		cout << n-rand()%n << "\n";
	}
	return 0;
}

