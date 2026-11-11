#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2, fs1, fs2;
	char a, b;
	int f=0;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2)cout << "1" << "\n";
	else cout << "0" << "\n";
	for(int i=0; i<s1.size()-1; i++)fs1+=s1[i];
	for(int i=0; i<s2.size()-1; i++)fs2+=s2[i];
	if(fs1==fs2)cout << "1" << "\n";
	else cout << "0" << "\n";
	for(int i=0; i<s1.size(); i++)a=s1[i];
	for(int i=0; i<s2.size(); i++)b=s2[i];
	if(fs1==fs2&&a<='C'&&b<='C'||fs1==fs2&&a>'C'&&b>'C')
	{
		cout << "1" << "\n";
		f=1;	
	}
	else cout << "0" << "\n";
	if(f==1)
	{
		if(a-'A'+1==b-'A'||a-'A'-1==b-'A')cout << "1" << "\n";
		else cout << "0" << "\n";
	}
	else cout << "0" << "\n";
	return 0;
}
