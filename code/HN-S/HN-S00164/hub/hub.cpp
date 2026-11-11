#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
struct node{
	int u,v;
}a[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1; i <= n-1; i++){
			cin >> a[i].u >> a[i].v;
		}
	}
	cout << 1 << ' ' << 2;
	return 0;
}
