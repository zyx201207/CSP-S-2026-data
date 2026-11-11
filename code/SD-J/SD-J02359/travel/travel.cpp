//#include <bits/stdc++.h>
#include <iostream>
#define int long long
using namespace std; 

bool vis[200];

signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout); 

	string ch1, id1, ch2, id2; 
	cin >> ch1 >> id1 >> ch2 >> id2;
	vis['A'] = 1, vis['B'] = 1, vis['C'] = 1;
	
	if(ch1 != ch2) { return cout << "0000", 0; } 
	cout << 1;
	
	string s1 = id1.substr(0, 2), s2 = id2.substr(0, 2);
	if(s1 != s2) { return cout << "000", 0; }
	cout << 1;
	
	char c_1 = id1[2], c_2 = id2[2];
	if(vis[c_1] + vis[c_2] == 1) { return cout << "00", 0; }
	cout << 1;
	
	if(vis[c_1] + vis[c_2] == 0) { return cout << 1, 0; } 
	
	if(c_1 == 'A' and c_2 == 'B' or c_1 == 'B' and c_2 == 'C'
	or c_2 == 'A' and c_1 == 'B' or c_2 == 'B' and c_1 == 'C') {
		return cout << 1, 0;
	} 
	
	return cout << 0, 0;
}  
