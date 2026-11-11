#include<bits/stdc++.h>
using namespace std;

int c,t;
long long n,d;
long long x[100005];
int ans;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> x[i];
		}
		for(int i = 1;i <= n;i++){
			if(x[i+3] - x[i] == d*2-1) ans++;
		}
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}
