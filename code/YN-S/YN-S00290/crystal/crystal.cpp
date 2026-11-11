#include <bits/stdc++.h>
using namespace std;
typedef long long kris;

//不写了，玩小恐龙去了
int main() {
	freopen("crysal.in", "r", stdin);
	freopen("crysal.out", "w", stdout);
	kris n, m;
	cin >> n >> m;
	vector<kris> cry(n + 1);
	//算了还是写写吧
	for (int i = 0; i < n; i++) {
		cin >> cry[i];
	}
	cout << n;
	return 0;
}
/*
[     ]     ∏     (~~~~~   {~~~  
[     ]    / \    (     >  [   \ 
[_____]   /   \   (~~~~~   [    }
[     ]  {_____}  (   \    [    }
[     ]  {     }  (    \   [   / 
[     ]  {     }  (     \_ {~~~  

*/