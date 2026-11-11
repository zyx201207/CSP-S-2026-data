#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >>c2 >> s2;
	if(c1 == c2) cout << "1";
	else{ 
		cout << "0000";
		return 0;
	}
	if(s1[0] == s2[0] && s1[1] == s2[1]) cout << "1";
	else{
		cout << "000";
		return 0;
	}
	char l1 = s1[2],l2 = s2[2];
	if(l1 == 'A' && l2 == 'B' || 
	   l1 == 'A' && l2 == 'C' || 
	   l1 == 'B' && l2 == 'C' || 
	   l2 == 'A' && l1 == 'B' || 
	   l2 == 'A' && l1 == 'C' || 
	   l2 == 'B' && l1 == 'C' ||
	   l2 == 'D' && l1 == 'F' || 
	   l2 == 'F' && l1 == 'D') cout << "1";
	else{
		cout << "00";
		return 0;
	}
	if(l1 == 'A' && l2 == 'B' || 
	   l1 == 'B' && l2 == 'C' || 
	   l2 == 'A' && l1 == 'B' || 
	   l2 == 'B' && l1 == 'C' ||
	   l2 == 'D' && l1 == 'F' || 
	   l2 == 'F' && l1 == 'D') cout << "1";
	else{
		cout << "0";
		return 0;
	}
}

