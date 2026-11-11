#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	cout << (c1 == c2);
	if(c1 == c2){
	bool f = (s1[0] == s2[0]&&s1[1] == s2[1]);
	cout << f;
	
	bool f1 = (s1[2] >='A' && s1[2] <='C')&&(s2[2] >='A' && s2[2] <='C');
	bool f2 = (s1[2] >='D' && s1[2] <='F')&&(s2[2] >='D' && s2[2] <='F');
	bool f3 = (s1[2] =='D' && s2[2] =='C')||(s1[2] =='C' && s2[2] =='D');
	cout << (f && (f1||f2) && !f3);
	
	
	char c[2]; c[0] = s1[2]; c[1] = s2[2]; sort(c,c+2);
	cout << ((f2||(c[0]=='A'&&c[1]=='B')||(c[0]=='B'&&c[1]=='C')) && f);
	}
	
	
	else{cout << 0 << 0<<0;
	}
	return 0;
}
