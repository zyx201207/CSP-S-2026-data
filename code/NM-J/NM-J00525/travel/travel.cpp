#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,sr,cx,sx;
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx) cout<<"1";
	  else cout<<"0";
	if((sr[0]==sx[0])&&(sr[1]==sx[1])&&(cr==cx)) cout<<"1";
	  else cout<<"0";
	if((sr[0]==sx[0])&&(sr[1]==sx[1])&&(cr==cx)&&((sr[2]=='A'&&sx[2]=='B')||(sr[2]=='B'&&sx[2]=='A')||(sr[2]=='C'&&sx[2]=='A')||(sr[2]=='A'&&sx[2]=='C')||(sr[2]=='C'&&sx[2]=='B')||(sr[2]=='B'&&sx[2]=='C')||(sr[2]=='F'&&sx[2]=='D')||(sr[2]=='D'&&sx[2]=='F'))) cout<<"1";
	  else cout<<"0";
	if((sr[0]==sx[0])&&(sr[1]==sx[1])&&(cr==cx)&&((sr[2]=='A'&&sx[2]=='B')||(sr[2]=='B'&&sx[2]=='A')||(sr[2]=='C'&&sx[2]=='A')||(sr[2]=='A'&&sx[2]=='C')||(sr[2]=='C'&&sx[2]=='B')||(sr[2]=='B'&&sx[2]=='C')||(sr[2]=='F'&&sx[2]=='D')||(sr[2]=='D'&&sx[2]=='F'))&&((sr[2]=='A'&&sx[2]=='B')||(sr[2]=='B'&&sx[2]=='A')||(sr[2]=='C'&&sr[2]=='B')||(sr[2]=='B'&&sr[2]=='C')||(sr[2]=='F'&&sr[2]=='D')||(sr[2]=='D'&&sr[2]=='F'))) cout<<"1";
	  else cout<<"0";
	fclose(stdin);
	fclose(stdout); 
	return 0; 
} 
