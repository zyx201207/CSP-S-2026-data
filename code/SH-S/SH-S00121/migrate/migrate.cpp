#include <iostream>
using namespace std;
int c,t;
void solve(){
	int n,d;
	cin >> n >> d;
	if(c == 11 || c == 12){
		int a;
		cin >> a;
		int ans = 0;
		while(n >= 4){
			n--;
			if(a >= d)ans++;
		}
		cout << ans << endl;
	}else{
		cout << 0 << endl;
	}
}
int main(){
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)solve();
}
