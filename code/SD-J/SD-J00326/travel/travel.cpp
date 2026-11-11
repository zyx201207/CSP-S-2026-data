#include<bits/stdc++.h>
using namespace std;
string ans="";
int main(){
	freopen("travle.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>> c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1[1]==s2[1]&&s1[0]==s2[0]){
			if(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D'){
				if(s1[2]==s2[2]+1||s1[2]==s2[2]-1||s2[2]=='F'&&s2[2]==s1[2]+2||s1[2]=='F'&&s1[2]==s2[2]+2){
					ans="1111";
				}
				else ans="1110";
			}
			else ans="1100";
		}
		else ans="1000";
	}
	else ans="0000";
	cout<<ans;
	return 0;
} 
