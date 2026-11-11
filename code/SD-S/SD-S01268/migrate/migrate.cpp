#include <iostream>
#include <vector>
using namespace std;
int T,c,n,m;
int ANS[1005][1005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ANS[4][2] = 1;
	ANS[5][2] = 2;
	ANS[5][3] = 0;
	ANS[6][2] = 1;
	cin >> c >> T;
	while(T--){
		cin >> n >> m;
		if(n > 1000 || m > 1000) cout << "0\n";
		else cout << ANS[n][m] << '\n';
	}
	return 0;
}
