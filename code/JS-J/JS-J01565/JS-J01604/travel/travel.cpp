#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ___c1,___s1,___c2,___s2;
	cin >> ___c1 >> ___s1 >> ___c2 >> ___s2;
	if(___c1 == ___c2) cout << 1;
	else{
		cout << "0000\n";
		return 0;
	}
	if(___s1[0] == ___s2[0] && ___s1[1] == ___s2[1]) cout << 1;
	else{
		cout << "000\n";
		return 0;
	}
	char a = ___s1[2],b = ___s2[2];
	set<char> yice = {'A','B','C'},ceyi = {'D','F'};
	if((yice.count(a) && ceyi.count(b)) || (yice.count(b) && ceyi.count(a))){
		cout << "00\n";
		return 0;
	}else cout << 1;
	if(ceyi.count(a) && ceyi.count(b)) cout << 1;
	else{
		if(a + 1 == b || b + 1 == a) cout << 1;
		else cout << 0;
	}
	cout << "\n";
	return 0;
}
