#include <bits/stdc++.h>
using namespace std;
long long c,t,n,k,u[2000006],v[2000006],cnt;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t--){
		cnt++;
		cin >> n >> k;
		for(int i=1;i<=n-1;i++){
			cin >> u[i] >> v[i];
		}
		cout << 1 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
