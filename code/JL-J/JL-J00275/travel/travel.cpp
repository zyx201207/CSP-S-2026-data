#include<bits/stdc++.h>
using namespace std;
char c1[4],s1[4],c2[4],s2[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]!=c2[0]||c1[1]!=c2[1])cout<<"0000";
	else if(s1[0]!=s2[0]||s1[1]!=s2[1])cout<<"1000";
	else if((s1[2]<='C'&&s2[2]>'C')||(s1[2]>'C'&&s2[2]<='C'))cout<<"1100";
	else if((s1[2]=='A'&&s2[2]!='B')||(s1[2]=='B'&&(s2[2]!='A'&&s2[2]!='C'))||(s1[2]=='C'&&s2[2]!='B')||(s1[2]=='D'&&s2[2]!='F'))cout<<"1110";
	else cout<<"1111"<<endl;
	return 0;
}
