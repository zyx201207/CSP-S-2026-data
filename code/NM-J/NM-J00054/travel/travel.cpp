#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
string s1,s2;
string c1,c2;
string t1,t2;
char p1,p2;
bool f1,f2,f3,f4;
inline bool check1(char a,char b)
{
	return (a=='D'&&b=='F')||(a=='F'&&b=='D')||(a=='A'&&(b=='C'||b=='B'))||(a=='B'&&(b=='C'||b=='A'))||(a=='C'&&(b=='A'||b=='B'));
}
inline bool check2(char a,char b)
{
	return (a=='D'&&b=='F')||(a=='F'&&b=='D')||(a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||(a=='C'&&b=='B');
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	f1 = (c1 == c2);
	for (int i = 0;i < 2;i++)
	{
		t1 += s1[i];
		t2 += s2[i];
	}
	p1 = s1[2];
	p2 = s2[2];
	f2 = (f1&&(t1 == t2));
	f3 = (f2&&check1(p1,p2));
	f4 = (f3&&check2(p1,p2));
	cout << f1 << f2 << f3 << f4;
	return 0;
}
