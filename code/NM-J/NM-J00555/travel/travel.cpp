#include<bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	if(c1==c2) cout<<1;
	 else cout<<0000;
	if(s1[1]==s2[1]&&s1[2]==s2[2]) cout<<1;
	else {cout<<000;}
	if((char(s1[3])<=char('C')&&char(s2[3])<=char('C'))||(char(s1[3])>=char('D')&&char(s2[3])>=char('D'))) cout<<1;
	  else {cout<<00;} 
	if((char(s1[3])-char(s2[3])==1)||(char(s2[3])-char(s1[3])==1)) cout<<1;
	  else {cout<<0;}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
