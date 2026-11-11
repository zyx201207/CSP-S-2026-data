#include <iostream>
using namespace std;
int main ()
{
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	string a[4];
	
	cin >> c1 >> s1 >> c2 >> s2; 
	if (c1[0]-'0'==c2[0]-'0')
		a[0]='1';
	else
		a[0]='0';
		
	if (c1[0]-'0'==c2[0]-'0' && s1[0]-'0'==s2[0]-'0')
		a[1]='1';
	else
		a[1]='0';
		
	if (c1[0]-'0'==c2[0]-'0' && s1[0]-'0'==s2[0]-'0' && s1[1]-'0'==s2[1]-'0')
		a[2]='1';
	else
		a[2]='0';
		
	if (c1[0]-'0'==c2[0]-'0' && s1[0]-'0'==s2[0]-'0' && s1[1]-'0'==s2[1]-'0')
		a[3]='1';
	else
		a[3]='0';
		
	cout << a;
}
