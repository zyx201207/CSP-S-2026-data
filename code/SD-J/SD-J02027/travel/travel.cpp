#include<bits/stdc++.h>
using namespace std;
int c1, c2, ss1, ss2;
char s1, s2;
int main(){
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	scanf ("%d%d%c%d%d%c", &c1, &ss1, &s1, &c2, &ss2, &s2);
	cout << (c1 == c2);
	if (c1 != c2){
		cout << "000";
		return 0;
	}
	cout << (ss1 == ss2);
	if (ss1 == ss2){
		if((s1 == 'A' || s1 == 'B'|| s1 == 'C') && (s2 == 'D' || s2 == 'E') || (s2 == 'A' || s2 == 'B'|| s2 == 'C') && (s1 == 'D' || s1 == 'E')){
			cout << "00";
			return 0;
		}
		else{
			cout << '1' << (abs (s1 - s2) == 1);
		}
	}
	else cout << "00";
	return 0;
}
