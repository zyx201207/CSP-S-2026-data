#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,s;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	s="0000";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		s[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			s[1]='1';
			a=s1[2]-'A'+1;
			b=s2[2]-'A'+1;
			if(a<=3)c=1;
			else c=2;
			if(b<=3)d=1;
			else d=2;
			if(c==d){
				s[2]='1';
				if(abs(a-b)==1)s[3]='1';
			}
		}
	}
	cout<<s;
	return 0;
}
