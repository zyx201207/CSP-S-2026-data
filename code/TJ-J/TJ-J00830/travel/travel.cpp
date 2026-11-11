#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2,s="0000";
	cin>>s1>>c1>>s2>>c2;
	if(c1[2]=='F') c1[2]='E';
	if(c2[2]=='F') c2[2]='E';
	if(s1==s2){
		s[0]='1';
		if(c1[0]==c2[0] and c1[1]==c2[1]){
			s[1]='1';
			if(c1[2]<='C' and c2[2]<='C' or c1[2]>='D' and c2[2]>='D'){
				s[2]='1';
				if(c1[2]+1==c2[2] or c1[2]-1==c2[2]) s[3]='1';
			}
		}
	}
	cout<<s;
	return 0;
}
