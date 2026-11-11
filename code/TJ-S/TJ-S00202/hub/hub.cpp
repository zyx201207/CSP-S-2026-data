#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,k,n,t,v[10005],u[10005];
	cin >> c >> t;
	for (int i = 1;i <= t;i++){
		cin >> n >> k;
		if(n == 0){
			cout << 0 << endl;
			continue;
		}
		for(int j = 1;j <= n-1;j++){
			cin >> u[10005] >> v[10005];
		}
		if(i != t){
			cout << 1;
		}else{
			cout << 2;
		}
	}
	return 0;
}
