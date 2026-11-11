#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	int f1 = 1;
	for(int i = 0; i < c1.size(); i ++){
		if(c1[i] != c2[i]) f1 = 0;
	}
	cout << f1;
	int f2 = f1;
	if(f2 == 0) cout << 0;
	else{
		for(int i = 0; i < s1.size()-1; i ++){
			if(s1[i] != s2[i]) f2 = 0;
		}
		cout << f2;
	}
	int ss1 = int(s1[2]-'A'), ss2 = int(s2[2]-'A');
	int f3 = f2;
	if(f3 == 0) cout << 0;
	else{
		if((ss1<=2&&ss2<=2) || (ss1>=3&&ss2>=3)) f3 = 1;
		else f3 = 0;
		cout << f3;
	}
	if(f3 == 0) cout << 0;
	else{
		if(min(ss1,ss2)==0 && max(ss1,ss2)==2) cout << 0;
		else cout << 1;
	}
	return 0;
}