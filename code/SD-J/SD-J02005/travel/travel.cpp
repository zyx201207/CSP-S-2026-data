#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s2,c3,s4;
	cin>>c1>>s2>>c3>>s4;
	if(c1==c3) cout<<1;
	else cout<<0;
	if(c1==c3 && s2[0]==s4[0] && s2[1]==s4[1]) cout<<1;
	else cout<<0;
	if(c1==c3 && s2[0]==s4[0] && s2[1]==s4[1] && ((s2[2]=='A' && s4[2]=='B') || (s2[2]=='A' && s4[2]=='C') || (s2[2]=='B' && s4[2]=='A') || (s2[2]=='B' && s4[2]=='C') || (s2[2]=='C' && s4[2]=='A') || (s2[2]=='C' && s4[2]=='B') || (s2[2]=='D' && s4[2]=='F') || (s2[2]=='F' && s4[2]=='D'))) cout<<1;
	else cout<<0;
	if(c1==c3 && s2[0]==s4[0] && s2[1]==s4[1] && ((s2[2]=='A' && s4[2]=='B') || (s2[2]=='B' && s4[2]=='C') || (s2[2]=='D' && s4[2]=='F') || (s2[2]=='B' && s4[2]=='A') || (s2[2]=='C' && s4[2]=='B') || (s2[2]=='F' && s4[2]=='D'))) cout<<1;
	else cout<<0;
	return 0;
}
