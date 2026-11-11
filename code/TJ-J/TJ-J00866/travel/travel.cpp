#include<bits/stdc++.h>
using namespace std;

#define int long long

string c1,s1,c2,s2;

signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	bool q1=(c1==c2);
	bool q2=(q1&&s1[0]==s2[0]&&s1[1]==s2[1]);
	bool q3=0;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
		q3=(s2[2]=='A'||s2[2]=='B'||s2[2]=='C');
	else
		q3=(s2[2]=='D'||s2[2]=='E');
	q3=(q3&&q2);
	bool q4=(q3&&abs(s2[2]-s1[2])==1);
	cout<<q1<<q2<<q3<<q4;
	return 0;
}
