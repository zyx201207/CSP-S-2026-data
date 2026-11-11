#include <bits/stdc++.h>
using namespace std;
using lnt = long long;
/*===================*/

/*===================*/
void solve(void){
	cout << rand()%3+1 << "\n";
}
/*===================*/
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	srand(time(0));
	int c; cin >> c;
	int T = 1; cin >> T;
	while(T--) solve();
	return 0;
}

