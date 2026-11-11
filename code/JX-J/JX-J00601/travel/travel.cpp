#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,t1,t2;
long long l1,l2;
bool f1,f2;
bool q1()
{
    return c1==c2;
}
bool q2()
{
    return 1-f2;
}
bool q3()
{
    return ('A'<=s1[l1]&&s1[l1]<='C'&&'A'<=s2[l2]&&s2[l2]<='C')||f1;
}
bool q4()
{
    return abs(s1[l1]-s2[l2])==1||f1;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	long long i=0;
	l1=s1.size()-1,l2=s2.size()-1;
	if((s1[l1]=='D'&&s2[l2]=='F')||(s1[l1]=='F'&&s2[l2]=='D'))
        f1=1;
	while('0'<=s1[i]&&s1[i]<='9'&&'0'<=s2[i]&&s2[i]<='9')
    {
        if(s1[i]!=s2[i])f2=1;
        i++;
    }
	if(c1==c2)cout<<1;
    else cout<<0;
	if(q1()&&q2())cout<<1;
	else cout<<0;
	if(q1()&&q2()&&q3())cout<<1;
	else cout<<0;
	if(q1()&&q2()&&q3()&&q4())cout<<1;
	else cout<<0;
	return 0;
}
