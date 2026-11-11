#include<bits/stdc++.h>
using namespace std;
long long int ans1,ans2,ans3,ans4,a,b;
string s1,s2,s3,s4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
cin>>s1>>s2>>s3>>s4;
if(s1==s3)
{
ans1=1;
if( (s2[0]-'0')*10 + (s2[1]-'0') == (s4[0]-'0')*10 + (s4[1]-'0') )
{
	
ans2=1;
a=s2[2]; b=s4[2];
if((a<=67&&a>=65 && b<=67&&b>=65) || (a>67&&a<=70 && b<=70&&b>=68)  )
ans3=1;
}
}
if(a-b==-1||a-b==1)
{
	if(! ((a==67&b==68)||(a==68&&b==67)))
	ans4=1;
}
cout<<ans1<<ans2<<ans3<<ans4;
return 0;
}
// 65 66 67 68 E 70
//02 01A 02 01B
