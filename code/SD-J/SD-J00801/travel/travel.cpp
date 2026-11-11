#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define LYT ios::sync_with_stdio(0),cin.tie(0)
const int N = 5e5 + 10;
string c1,s1,c2,s2;
signed main(){LYT;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
		if(s1[0] + s1[1] == s2[0] + s2[1]){
			cout << 1;
			if((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F'))){
				cout << 1;
				if((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') && ((s1[2] != 'A' && s2[2] != 'C') && (s1[2] != 'C' && s2[2] != 'A'))) cout << 1;
				else if((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')) cout << 1;
				else cout << 0; 
			}
			else cout << "00";
		}
		else cout << "000";
	}else cout << "0000";
	return 0;
} 
