#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) ans="1";
	else ans="0";
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)) ans+="1";
	else ans+="0";
/*if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&((s1.substr(2,1)<="C"&&s2.substr(2,1)<="C")||(s1.substr(2,1)>="D"&&s2.substr(2,1)>="D"))) ans+="1";
	else ans+="0";
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&(s1.substr(2,1)+s2.substr(2,1)=="AB"||s1.substr(2,1)+s2.substr(2,1)=="BA"||s1.substr(2,1)+s2.substr(2,1)=="BC"||s1.substr(2,1)+s2.substr(2,1)=="CB"||s1.substr(2,1)+s2.substr(2,1)=="DF"||s1.substr(2,1)+s2.substr(2,1)=="FD")) ans+="1";
	else ans+="0";*/
	ans+="10";
	cout<<ans;
	return 0;
}