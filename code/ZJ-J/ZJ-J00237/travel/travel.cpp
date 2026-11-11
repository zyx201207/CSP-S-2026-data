#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) cout << '1';
	else{
		cout << "0000";
		return 0;
	}
	if(s1[0] == s2[0] && s1[1] == s2[1]){
		int f1,f2;
		if(s1[2] == 'D' || s1[2] == 'F') f1 = 1;
		else f1 = 2;
		if(s2[2] == 'D' || s2[2] == 'F') f2 = 1;
		else f2 = 2;
		if(f1 == f2){
			if(f1 == 1 && f2 == 1) cout << "111";
			else{
				int w1,w2;
				if(s1[2] == 'A') w1 = 1;
				else if(s1[2] == 'B') w1 = 2;
				else w1 = 3;
				if(s2[2] == 'A') w2 = 1;
				else if(s2[2] == 'B') w2 = 2;
				else w2 = 3;
				if(abs(w1 - w2) == 1) cout << "111";
				else cout << "110";
			}
		}
		else cout << "100";
	}
	else cout << "000";
	return 0;
}