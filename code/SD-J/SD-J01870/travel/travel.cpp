#include<bits/stdc++.h>
using namespace std;
#define C ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long
int main(){
	C
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s="0000";
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		s[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			s[1]='1';
			if(((s1[2]=='A'||s1[2]=='B'||s2[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))){
				s[2]='1';
				if(((s1[2]-1)==s2[2]||(s1[2]+1)==s2[2])&&((s1[2]!='D'&&s2[2]!='C')&&(s1[2]!='C'&&s2[2]!='D'))){
					s[3]='1';
				}
			}
		}
	}
	cout<<s;
	return 0;
}
