#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	int c1,c2;
	cin>>c1>>s1>>c2>>s2;
	int q1=0,q2=0,q3=0,q4=0;
	char t1=s1[2],t2=s2[2];
	if(c1==c2)
		q1=1;
	if(q1&&s1[0]==s2[0]&&s1[1]==s2[1])
		q2=1;
	if(q1&&q2&&((t1>='A'&&t1<='C'&&t2>='A'&&t2<='C')||(t1>='D'&&t1<='F'&&t2>='D'&&t2<='F')))
		q3=1;
	if(q1&&q2&&q3&&(abs(t1-t2)==1||t1=='F'&&t2=='D'||t1=='D'&&t2=='F'))
		q4=1;
	cout<<q1<<q2<<q3<<q4;
	return 0;
}
