#include<bits/stdc++.h>
using namespace std;
#define int long long
int cr, sr1, cx, sx1;
char sr2, sx2;
char nu;
signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> cr >> sr1 >> sr2 >> cx >> sx1 >> sx2;
	int flag = 0;
	if(cr == cx){
		cout << "1";
		flag = 1;
	}
	else cout << "0";
	if(flag == 1 && sr1 == sx1) cout << "1";
	else {
		cout << "0";
		flag = 0;
	}
	if(flag == 1 && ((('A' <= sr2 && sr2 <='C') && ('A' <= sx2 && sx2 <= 'C')) || ((sr2 == 'D' || sr2 == 'F') && (sx2 == 'D' || sx2 == 'F')))){
		cout << "1";
	}  else {
		cout <<"0";
		flag = 0;
	}
	if(flag == 1 && (sr2 + 1 == sx2 || sx2 + 1 == sr2)){
		cout << "1";
	}else cout << "0";
	
	return 0;
}
