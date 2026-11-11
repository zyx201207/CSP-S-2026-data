//SN-J00815 李雨轩 陕西延安中学 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool b1=false,b2=false;
	if (s1[2]>=65 && s1[2]<=67 && s2[2]>=65 && s2[2]<=67) b1=true;
	if (s1[2]>=68 && s1[2]<=69 && s2[2]>=68 && s2[2]<=69) b2=true;
	if (c1==c2) cout << 1;
	else cout << 0;
	if (c1==c2 && s1[0]==s2[0] && s1[1]==s2[1]) cout << 1;
	else cout << 0;
	if (c1==c2 && s1[0]==s2[0] && s1[1]==s2[1]&&(b1||b2)) cout << 1;
	else cout << 0;
	if (c1==c2 && s1[0]==s2[0] && s1[1]==s2[1]&&(b1||b2)&&((b1 && abs(s1[2]-s2[2])<=1)|| b2)) cout << 1;
	else cout << 0;	
	return 0;
}
