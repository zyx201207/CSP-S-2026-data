#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6 + 5;
string c1, s1, c2, s2;
LL A;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){//同车厢 
		cout << 1;
		A ++;
		if(s1[0] == s2[0] && s1[1] == s2[1]){//同排 
			cout << 1;
			A ++;
			if(s1[2] <= 'C' && s2[2] <= 'C' || s1[2] > 'C' && s2[2] > 'C'){//一侧 
				cout << 1;
				A ++;
				if(s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2]){//邻座 
					cout << 1;
					A ++;
				} 
			}
		}
	}
	for(int i = 1; i <= 4 - A; i ++) cout << 0;
	return 0;
}
