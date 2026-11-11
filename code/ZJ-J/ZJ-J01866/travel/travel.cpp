// Pass 100
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string c1, s1, c2, s2;

int to_int(string x){
	int ans = 0;
	for (int i = 0; i < x.size(); i++)
		if (x[i] >= '0' && x[i] <= '9')
			ans = ans * 10 + x[i] - '0';
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	//
	cin >> c1 >> s1 >> c2 >> s2;
	
	//
	int a = to_int(c1), b = to_int(s1), c = to_int(c2), d = to_int(s2);
	bool flag1 = 0, flag2 = 0;
	if (s1[2] == 'D' || s1[2] == 'F') flag1 = 1;
	if (s2[2] == 'D' || s2[2] == 'F') flag2 = 1;
 	
	//
	if (a == c){
		cout << '1';
		if (b == d){
			cout << '1';
			if (flag1 == flag2){
				cout << '1';
				if ((abs((int)(s1[2]) - (int)(s2[2])) == 1 && (int)(s1[2]) + (int)(s2[2]) != (int)('C') + (int)('D'))) cout << 1;
				else cout << '0';
			}
			else cout << "00";
		}
		else cout << "000";
	} 
	else cout << "0000";
	
	return 0;
}