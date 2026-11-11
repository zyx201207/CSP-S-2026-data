#include<bits/stdc++.h> 

using namespace std;

string c1, c2, s1, s2;
bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
int main () 
{
	freopen("travel.in", "r", stdin); 
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
	    flag1 = true;
	if (flag1&&(s1[0] == s2[0]&&s1[1] == s2[1]))
	    flag2 = true;
	if (flag2&&(((s1[2] == 'A'||s1[2] == 'B'||s1[2] == 'C')&&(s2[2] == 'A'||s2[2] == 'B'||s2[2] == 'C'))||((s1[2] == 'D'||s1[2] == 'F')&&(s2[2] == 'D'||s2[2] == 'F'))))
	    flag3 = true;
	if (flag3&&((s1[2] != 'C' && s2[2] != 'D')||(s1[2] != 'D'&&s1[2] != 'C')&&(s1[2] + 1 == s2[2]||s2[2] + 1 == s1[2])))
	    flag4 = true;
	if (flag1) cout << 1;
	else cout << 0;
	if (flag2) cout << 1;
	else cout << 0;
	if (flag3) cout << 1;
	else cout << 0;
	if (flag4) cout << 1;
	else cout << 0;
	fclose(stdin);
	fclose(stdout);	
	return 0;
} 
