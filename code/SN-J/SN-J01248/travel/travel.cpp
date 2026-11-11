#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;

int pos(char c)
{
	return c-'A'-(c>'D');
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int flag1=(c1==c2);
	int flag2=flag1 && s1.substr(0,2)==s2.substr(0,2);
	int x=pos(s1[2]),y=pos(s2[2]);
	int flag3=flag2 && (x<3)==(y<3);
	int flag4=flag3 && abs(x-y)==1;
	printf("%d%d%d%d\n",flag1,flag2,flag3,flag4);
	return 0;
}
