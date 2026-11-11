#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main(){
	freopen("travel.in ","r",stdin);
	freopen("travel.out ","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	
	bool chexiang = c1 == c2;
	if(chexiang)cout << 1;
	else cout << 0;
	
	
	bool pai = (s1[0] == s2[0]) && (s1[1] == s2[1]);
	if(chexiang && pai)cout << 1;
	else cout << 0;
	
	
	bool ce = (s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C' ) || ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F' ));
	if(chexiang && pai && ce)cout << 1;
	else cout << 0;
	
	
	bool xianglin = 
	(s1[2] == 'A' && s2[2] == 'B') ||
	(s1[2] == 'B' && s2[2] == 'A') ||
	(s1[2] == 'B' && s2[2] == 'C') ||
	(s1[2] == 'C' && s2[2] == 'B') ||
	(s1[2] == 'D' && s2[2] == 'F') ||
	(s1[2] == 'F' && s2[2] == 'D');
	
	if(chexiang && pai && ce && xianglin)cout << 1;
	else cout << 0;
	
	
	return 0;
} 
