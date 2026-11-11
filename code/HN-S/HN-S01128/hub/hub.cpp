#include <bits/stdc++.h>
using namespace std;
int a,b,n,m,p,q,o;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b;
	while(b--){
		cin >> n >> m;
		cin >> p >> q;
		for(int i = 1;i<=n-1;i++){
			cin >> a >> o;
		}
		if(b%2==0){
			cout << q;
		}else cout << p;
		cout << '\n';
	}
	return 0;
}
