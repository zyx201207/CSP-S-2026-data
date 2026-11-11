#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char s1[3],s2[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	char l1=s1[2],l2=s2[2];
	if(!(c1==c2))cout<<"0000";
	else if(!(s1[0]==s2[0]&&s1[1]==s2[1]))cout<<"1000";
	else if(!((s1[2]<'D')==(s2[2]<'D')))cout<<"1100";
	else if(!(s1[2]==s2[2])){
		if(s1[2]<'D'&&s1[2]!='B'&&s2[2]!='B')cout<<"1110";
		else cout<<"1111";
	}
	return 0;
} 
