#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)b=1;
	cout<<b;
	if(!(s1[0]==s2[0]&&s1[1]==s2[1]))b=0;
	cout<<b;
	if(!((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')))b=0;
	cout<<b;
	if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A'))b=0;
	cout<<b;
	return 0;
}