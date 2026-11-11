#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int cx,cy,sx,sy;
int main(){
	freopen("travle.in","r",stdin);
	freopen("travle.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cx=(c1[0]-'0')*10+(c1[1]-'0');
	cy=(c2[0]-'0')*10+(c2[1]-'0');
	sx=(s1[0]-'0')*10+(s1[1]-'0');
	sy=(s2[0]-'0')*10+(s2[1]-'0');
	if(cx==cy){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(sx==sy){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((s1[2]-'A'<3&&s2[2]-'A'<3)||(s1[2]-'A'>=3&&s2[2]-'A'>=3)){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(s1[2]-'0'-(s2[2]-'0'))==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
