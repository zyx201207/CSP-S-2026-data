#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string s1,s2,c1,c2;
	cin>>s1>>s2>>c1>>c2;
	if(s2[2]=='F')s2[2]='E';
	if(c2[2]=='F')c2[2]='E';
	
	if(s1==c1)cout<<1;
	else cout<<0;
	if(s1==c1&&s2[0]==c2[0]&&s2[1]==c2[1])cout<<1;
	else cout<<0;
	if(s1==c1&&s2[0]==c2[0]&&s2[1]==c2[1]&&((s2[2]<='C'&&c2[2]<='C')||(s2[2]>'C'&&c2[2]>'C')))cout<<1;
	else cout<<0;
	if(s1==c1&&s2[0]==c2[0]&&s2[1]==c2[1]&&((s2[2]<='C'&&c2[2]<='C')||(s2[2]>'C'&&c2[2]>'C'))
	&&(abs(s2[2]-c2[2])==1))cout<<1;
	else cout<<0;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
