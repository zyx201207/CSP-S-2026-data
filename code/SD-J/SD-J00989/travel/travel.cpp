#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	//cout<<c1<<s1<<c2<<s2;
	if(c1==c2) cout<<1;
	else 
	{
		cout<<0;
	}
	//cout<<s1[1];
	//cout<<s1[0]*10+s1[1]<<endl<<s2[0]*10+s2[1]<<endl;
	if(s1[0]*10+s1[1]==s2[0]*10+s2[1]) cout<<1;
	else 
	{
		cout<<0;	
	}
	//cout<<endl<<s1[0]*10<<endl<<s2[0]*10+s2[1];
	if((s1[0]*10+s1[1]==s2[0]*10+s2[1])&&((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s2[2]=='A'&&s1[2]=='C')||(s2[2]=='A'&&s1[2]=='B')||(s2[2]=='B'&&s1[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='D'&&s1[2]=='F'))) cout<<1;
	else cout<<0;
	if(s1[2]++==s2[2]||s1[2]--==s2[2]||s2[2]--==s1[2]||s2[2]++==s1[2]) cout<<1;
	else cout<<0;
	return 0;
} 
