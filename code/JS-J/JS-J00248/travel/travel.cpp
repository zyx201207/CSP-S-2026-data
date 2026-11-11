#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string a1=s1.substr(0,2),a2=s2.substr(0,2);
	if(c1==c2)cout<<1;
	else cout<<0;
	if(c1==c2&&a1==a2)cout<<1;
	else cout<<0;
	if(c1==c2&&a1==a2&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')))cout<<1;
	else cout<<0;
	if(c1==c2&&a1==a2&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')))cout<<1;
	else cout<<0;
	return 0;
}
