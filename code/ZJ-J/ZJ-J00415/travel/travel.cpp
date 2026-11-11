#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool f = true;
	if(c1 == c2)
		cout << 1;
	else{
		cout << 0;
		f = false;
	}if(s1.substr(0,2) == s2.substr(0,2) and f)
		cout << 1;
	else{
		cout << 0;
		f = false;
	}if((s1[2] <= 'C' and s2[2] <= 'C'
		  or s1[2] > 'C' and s2[2] > 'C') and f)
		cout << 1;
	else{
		cout << 0;
		f = false;
	}if((abs((int)s1[2] - (int)s2[2]) == 1 and
			 not (s1[2] == 'C' and s2[2] == 'D') and
			 not (s1[2] == 'D' and s2[2] == 'C')) and f)
		cout << 1;
	else cout << 0;
	return 0;
}