#include<bits/stdc++.h>
using namespace std;
string c1 , s1 , c2 , s2;
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int tmp1 = (c1 == c2);
	int tmp2 = tmp1 && (s1[0] == s2[0]) && (s1[1] == s2[1]);
	int tmp3 = tmp1 && tmp2 && (((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) || ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')));
	char p1 = s1[2] , p2 = s2[2];
	if(p1 > p2) swap(p1 , p2);
	int tmp4 = tmp1 && tmp2 && tmp3 && ((p1 == 'A' && p2 == 'B') || (p1 == 'B' && p2 == 'C') || (p1 == 'D' && p2 == 'F'));
	cout << tmp1 << tmp2 << tmp3 << tmp4;
	return 0;
}
