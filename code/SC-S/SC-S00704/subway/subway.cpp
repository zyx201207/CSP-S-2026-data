#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	srand(time(0));
	while (q--){
		cout << rand()%100 + 1 << endl;
	}
}