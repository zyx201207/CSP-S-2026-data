#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int f[10] = {0,0,0,0,0};
	if  (c1 == c2){
		f[1] = 1;
		if (s1.substr(0,2) == s2.substr(0,2)){
			f[2] = 1;
			if (s1[2] <= 'C' && s2[2] <= 'C'){
				f[3] = 1;
			}
			if ((s1[2] <= 'C' && s2[2] <= 'C' && abs(s1[2] - s2[2]) == 1) || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')){
				f[3] = 1;
				f[4] = 1;
			}
		}
	}
	cout << f[1] << f[2] << f[3] << f[4] << endl;
	return 0;
} 
