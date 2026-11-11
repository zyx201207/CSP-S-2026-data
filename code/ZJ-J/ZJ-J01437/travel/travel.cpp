#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check1()
{
	for(char i='A';i<='C';i++)
		for(char j=i+1;j<='C';j++)
			if((s1[2]==i&&s2[2]==j)||(s1[2]==j&&s2[2]==i))
				return true;
	if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')) return true;
	return false;
}
bool check2()
{
	for(char i='A';i<='B';i++) if((s1[2]==i&&s2[2]==i+1)||(s1[2]==i+1&&s2[2]==i)) return true;
	if(s1[2]=='D'&&s2[2]=='F') return true;
	if(s1[2]=='F'&&s2[2]=='D') return true;
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("trevel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool q1=(c1==c2);
	bool q2=(s1[0]==s2[0]&&s1[1]==s2[1]);
	bool q3=check1();
	bool q4=check2();
	cout<<q1<<(q1&&q2)<<(q1&&q2&&q3)<<(q1&&q2&&q3&&q4);
	return 0;
}
