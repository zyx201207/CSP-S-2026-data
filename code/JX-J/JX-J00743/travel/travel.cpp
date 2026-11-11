#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool flag1=1,flag2=1,flag3=1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1==c2)
	{
		cout << 1;
		flag1=0;
	}
	else cout << 0;
	if (flag1==0 and s1[0]==s2[0] and s1[1]==s2[1])
	{
		cout << 1;
		flag2=0;
	}
	else cout << 0;
	char a1=s1[2],a2=s2[2];
	if (flag2==0 and ((a1=='E' and a2=='D') or (a1=='D' and a2=='E') or (a1=='A' and a2=='B') or (a1=='A' and a2=='C') or (a1=='B' and a2=='C') or (a2=='A' and a1=='B') or (a2=='A' and a1=='C') or (a2=='B' and a1=='C')))
	{
		cout << 1;
		flag3=0;
	}
	else cout << 0;
	if (flag3==0 and ((a1=='A' and a2=='B') or (a1=='E' and a2=='D') or (a1=='B' and a2=='C') or (a2=='A' and a1=='B') or (a2=='E' and a1=='D') or (a2=='B' and a1=='C'))) cout << 1;
	else cout << 0;
	return 0;
}
