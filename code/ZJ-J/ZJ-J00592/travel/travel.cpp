#include <bits/stdc++.h>
using namespace std;

string s1, s2;
string c1, c2;

int main(){
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios :: sync_with_stdio(false);
	cin.tie(0);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 != c2){
		cout << "0000";
		return 0;
	}
	
	int a1, a2;
	a1 = 0;
	a2 = 0;
	for(int i = 0; i < s1.size() - 1; ++ i){
		a1 = 10 * a1 + (s1[i] - '0');
		a2 = 10 * a2 + (s2[i] - '0');
	}
	
	if(a1 != a2){
		cout << "1000";
		return 0;
	}
	
	char o1, o2;
	o1 = s1[2];
	o2 = s2[2];
	
	if(o1 == 'A' || o1 == 'B' || o1 == 'C'){
		if(o2 != 'A' && o2 != 'B' && o2 != 'C'){
			cout << "1100";
			return 0;
		}
	}else{
		if(o2 != 'D' || o2 != 'F'){
			cout << "1100";
			return 0;
		}
	}
	
	int f1, f2;
	f1 = o1 - 'A';
	f2 = o2 - 'A';
	
	int maxx, minn;
	maxx = max(f1, f2);
	minn = min(f1, f2);
	
	if(maxx - minn == 1){
		cout << "1111";
	}else{
		cout << "1110";
	}
	
	return 0;
}