#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool b1,b2,b3,b4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2) b1=1;
	if(b1&&s1[0]==s2[0]&&s1[1]==s2[1]) b2=1;
	if(b2&&('A'<=s1[2]&&s1[2]<='C')&&('A'<=s2[2]&&s2[2]<='C')) b3=1;
	if(b2&&('D'<=s1[2]&&s1[2]<='F')&&('D'<=s2[2]&&s2[2]<='F')) b3=1;
	if(b3&&(abs((s1[2]-'A')-(s2[2]-'A'))==1)) b4=1;
	cout << b1 << b2 << b3 << b4;
	return 0;
} 
