#include<bits/stdc++.h>
using namespace std;

char c1, c2, s1, s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << 0000;
		return 0;
	}
	if(s1 - 'D' == s2 -'F'){
		cout << 1111;
		return 0;
	}
	cout << 1100;
	return 0;
}
