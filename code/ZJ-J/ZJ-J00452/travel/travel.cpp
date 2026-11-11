#include<bits/stdc++.h>
using namespace std;
bool xl(char a,char b){
	if(a=='A' and b=='B' or a=='B' and b=='A')return 1;
	else if(a=='B' and b=='C' or a=='C' and b=='B')return 1;
	else if(a=='D' and b=='F' or a=='F' and b=='D')return 1;
	else return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int f=0;
	
	if(c1[0]==c2[0] and c1[1]==c2[1])cout<<"1";
	else cout<<"0",f=1;
	
	if(s1[0]==s2[0] and s1[1]==s2[1] and f==0)cout<<"1";
	else cout<<"0",f=1;
	
	if(s1[2]-'A'<3 and s2[2]-'A'<3 and f==0 or s1[2]-'A'>=3 and s2[2]-'A'>=3 and f==0)
		cout<<"1";
	else cout<<"0",f=1;

	if(xl(s1[2],s2[2]) and f==0)cout<<"1";
	else cout<<"0";
	
	return 0;
}