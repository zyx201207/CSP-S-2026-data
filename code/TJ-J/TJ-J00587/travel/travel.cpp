#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	char t1=s1[0],t1_=s1[1],t1__=s1[2],t2=s2[0],t2_=s2[1],t2__=s2[2];
	bool flag3=abs(t1__-t2__)==1,flag2=(((t1__=='A'||t1__=='B'||t1__=='C')&&(t2__=='A'||t2__=='B'||t2__=='C'))||((t1__=='D'||t1__=='E')&&(t2__=='D'||t2__=='E')));
	if(c1!=c2)
		cout<<"0000";
	else if(!(t1==t2&&t1_==t2_))
		cout<<"1000";
	else if(!flag2)
		cout<<"1100";
	else if(!flag3)
		cout<<"1110";
	else
		cout<<"1111";
	return 0;
}
