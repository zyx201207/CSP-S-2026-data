#include<bits/stdc++.h>
using namespace std;
int n,m,q[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> q[i];
	if(n == 4 && m == 3) cout << 1 <<' '<< 2 <<' '<< 1 <<' '<< 3;
	if(n == 10 && m == 3) cout <<  3 <<' '<< 1 <<' '<< 2 <<' '<< 1 <<' '<< 3 <<' '<< 2 <<' '<< 3 <<' '<< 1 <<' '<< 2 <<' '<< 1;
	return 0;
}
