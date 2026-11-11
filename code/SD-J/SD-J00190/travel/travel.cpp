#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,c2,s1,s2;
	bool t3 = 0,t4 = 0,t5 = 0;
	cin >> c1 >> s1 >> c2 >> s2;
	char t1 = s1[2],t2 = s2[2];
	if(c1==c2)
	{
		t4 = 1;
		cout << 1;
	}
	else cout << 0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&t4)
	{
		t5 =1;
		cout << 1;
	}
	else cout << 0;
	if((((t1=='A'||t1=='B'||t1=='C')&&(t2=='A'||t2=='B'||t2=='C'))||((t1=='D'||t1=='F')&&(t2=='D'||t2=='F')))&&t4&&t5)
	{
		cout << 1;
		t3 = 1;
	}
	else cout << 0;
	if(t3&&t4&&t5&&abs(t1-t2)==1) cout << 1;
	else cout << 0;
	return 0;
}
