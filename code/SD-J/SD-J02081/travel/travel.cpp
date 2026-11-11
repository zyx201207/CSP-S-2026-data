#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2,g1,g2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << "0000";
		return 0;
	}
	cout << "1";
	g1 = s1.substr(0,2);
	g2 = s2.substr(0,2);
	if(g1 != g2){
		cout << "000";
		return 0;
	}
	cout << "1";
	if(!((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D'))){
		cout << "00";
		return 0;
	}
	cout << "1";
	if(abs(s1[2] - s2[2]) == 1) cout << "1";
	else cout << "0";
	return 0;
}
