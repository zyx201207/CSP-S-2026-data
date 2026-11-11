#include<bits/stdc++.h>
using namespace std;
int main(){
	fropen("travel.in","r",stdin);
	fropen("travel.out","w",stdout);
	char c1, s1, c2, s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==s1) cout<<"1";
	else cout<<"0";
	if(c2[1]==s2[1]) cout<<"1";
	else cout<<"0";
	if(c2[2]=='A'||'B'||'C' && s2[2]='A'||'B'||'C') cout<<"1";
	else if(c2[2]=='D'||'E' && s2[2]=='D'||'E') cout<<"1";
	else cout<<"0";
	if(c2[2]+1==s2[2]||c2[2]-1==s2[2]) cout<<"1";
	else cout<<"0";
	return 0;
}