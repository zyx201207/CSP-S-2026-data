//白屹桐  西安辅轮中学  SN-J00658 
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
string c1, s1, c2, s2;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2){
		cout << 0 << 0 << 0 << 0;
		return 0;
	}else{
		cout << 1;
		if (s1[0] == s2[0] && s1[1] == s2[1]){
			cout << 1;
			if (s1[2] <= 'C' && s1[2] >= 'A' && s2[2] <= 'C' && s2[2] >= 'A'){
				cout << 1;
				int x = s1[2] - 'A', y = s2[2] - 'A';
				if (abs(x - y) == 1){
					cout << 1;
				}else{
					cout << 0;
				}
			}else if(s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'D'){
				cout << 1 << 1;
			}else{
				cout << 0 << 0;
			} 
		}else{
			cout << 0 << 0 << 0;
		}
	}
	
	return 0;
}
