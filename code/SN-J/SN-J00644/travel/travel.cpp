//李思奇 83中学 SN-J00644 
#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main(){
	bool flag = true;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 == c2) cout << 1;
	else{cout << 0;flag = false;}

	if(s1.substr(0,1) == s2.substr(0,1))
		if(flag == true)
			cout << 1;
		else cout << 0;
	else{cout << 0;flag = false;}
	
	if(((s1[2] == 'A')||(s1[2]=='B')||(s1[2]=='C')) && ((s2[2] == 'A')||(s2[2]=='B')||(s2[2]=='C')) || ((s1[2] == 'D')||(s1[2]=='F')) && ((s2[2] == 'D')||(s2[2]=='F')))
		if(flag == true)
			cout << 1;
		else cout << 0;
	else{cout << 0;flag = false;}
	
	if(flag == true)
		if(((s1[2] == 'D')||(s1[2]=='F')) && ((s2[2] == 'D')||(s2[2]=='F')) || (((s1[2] == 'A')||(s1[2]=='B')) && ((s2[2] == 'A')||(s2[2]=='B'))||((s1[2] == 'B')||(s1[2]=='C')) && ((s2[2] == 'B')||(s2[2]=='C'))))
			cout << 1;
	else cout << 0;
	return 0;
}
