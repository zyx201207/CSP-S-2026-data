#include <bits/stdc++.h>
using namespace std;
int c, s, l, cc, ss, ll;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string sc;
	cin >> sc;
	c = int(sc[0] - '0') * 10 + int(sc[1] - '0');
	cin >> sc;
	l = int(sc[0] - '0') * 10 + int(sc[1] - '0');
	s = int(sc[2] - 'A') + 1;
	
	cin >> sc;
	cc = int(sc[0] - '0') * 10 + int(sc[1] - '0');
	cin >> sc;
	ll = int(sc[0] - '0') * 10 + int(sc[1] - '0');
	ss = int(sc[2] - 'A') + 1;	
	
	if(c != cc){
		cout << "0000";
	}else{
		if(l != ll) cout << "1000";
		else{
			if(!((1 <= ss && ss <= 3 && 1 <= s && ss <= 3) || (4 <= ss && ss <= 5 && 4 <= s && s <= 5))) cout << "1100";
			else{
				if(s + 1 == ss || s - 1 == ss) cout << "1111";
				else cout << "1110";				
			}

		}
	}
	return 0;
}

