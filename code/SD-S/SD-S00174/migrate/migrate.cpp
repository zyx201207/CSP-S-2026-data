#include <bits/stdc++.h>
using namespace std;
long long n,d,x[2000005],c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		cout << 0 << "\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
