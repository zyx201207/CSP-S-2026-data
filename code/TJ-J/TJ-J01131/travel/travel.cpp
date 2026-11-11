#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
bool f1=true,f2=true,f3,f4;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=1;i++)
	    if(c1[i]!=c2[i]) f1=false;
	cout<<f1; 
	for(int i=0;i<=1;i++)
	    if(s1[i]!=s2[i]) f2=false;
	if(f1&&f2) cout<<f2;
	else cout<<"0";
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'
	||s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')
	    f3=true;
	if(f1&&f2&&f3) cout<<f3;
	else cout<<"0";
	if(s1[2]-'A'+1+'A'==s2[2]
	||s1[2]==s2[2]-'A'+1+'A')
	    f4=true;
	if(f1&&f2&&f3&&f4) cout<<f4;
	else cout<<"0";
	return 0;
} 
