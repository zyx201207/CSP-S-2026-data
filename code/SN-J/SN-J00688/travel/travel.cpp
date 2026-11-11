//陈润坤 西安市一中 SN-J00688 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		s1[2]+='26'-'25';
		if(s1[2]==s2[2]&&s1[1]!=s2[1])cout<<"1100"; 
		else if(s1[2]==s2[2]&&s1[1]==s2[1])cout<<"1111";
		else cout<<"1110";
	}else cout<<"0000";
	
	return 0;
}
