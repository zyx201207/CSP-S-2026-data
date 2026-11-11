#include <bits/stdc++.h>
using namespace std;
int c,t,n,cnt;
long long d;
long long x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> x[i];
			if(x[i]-x[1]==3||x[i]-x[1]==4){
				cnt++;
			}
			
		}
	}
	if(cnt==0) cout << 0 << ' ';
	else cout << cnt << ' ';
	return 0;
}
