#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else cout<<0;
	
	if(c1!=c2) cout<<0;
	else if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1]) cout<<1;
	else cout<<0;
	
	if(c1!=c2 || s1[0]!=s2[0] || s1[1]!=s2[1])cout<<0;
	else if((s1[2]==char(67) && s2[2]==char(68)) || (s2[2]==char(67) && s1[2]==char(68)))cout<<0;
	else cout<<1;
	
	if(c1!=c2 || s1[0]!=s2[0] || s1[1]!=s2[1])cout<<0;
	else if(s1[2]==char(65) && s2[2]==char(66) || s1[2]==char(66) && s2[2]==char(67) || s1[2]==char(68) && s2[2]==char(70) || s2[2]==char(65) && s1[2]==char(66) || s2[2]==char(66) && s1[2]==char(67) || s2[2]==char(68) && s1[2]==char(70))cout<<1;
	else cout<<0;
	return 0;
}
