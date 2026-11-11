#include <bits/stdc++.h>
using namespace std;
string s1,t1,s2,t2;
int qwq1,qwq2;
bool check()
{
	if(qwq1==0&&qwq2<=2) return 1;
	if(qwq1==1&&qwq2<=2) return 1;
	if(qwq1==2&&qwq2<=2) return 1;
	if(qwq1>2&&qwq2>2)  return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>t1>>s2>>t2;
	if(s1==s2) printf("1");
	else printf("0");
	int num1 = 10*(t1[0]-'0')+(t1[1]-'0');
	int num2 = 10*(t2[0]-'0')+(t2[1]-'0');
	if(s1==s2&&num1==num2) printf("1");
	else printf("0");
	qwq1 = (t1[2]-'A');
	qwq2 = (t2[2]-'A');
	if(s1==s2&&num1==num2&&check()) printf("1");
	else printf("0");
	if(s1==s2&&num1==num2&&check()&&(abs(qwq1-qwq2)==1)) printf("1");
	else printf("0");
	return 0;
}//100