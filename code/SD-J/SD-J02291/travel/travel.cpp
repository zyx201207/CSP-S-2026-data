#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	getline(cin,s);
	int a1 = (s[0]-'0')*10+(s[1]-'0') , a2 = (s[3]-'0')*10+(s[4]-'0') , a3 = s[5] , b1 = (s[7]-'0')*10+(s[8]-'0') , b2 = (s[10]-'0')*10+(s[11]-'0') , b3 = s[12];
	if (a1 == b1){
		if (a2 == b2){
			if (('A' <= a3 && a3 <= 'C' && 'A' <= b3 && b3 <= 'C') || ('D' <= a3 && a3 <= 'E' && 'D' <= b3 && b3 <= 'E')){
				if (a3 == b3+1 || a3+1 == b3) cout << "1111";
				else cout << "1110";
			}
			else cout << "1100";
		}
		else cout << "1000";
	}
	else cout << "0000";
	return 0;
}
