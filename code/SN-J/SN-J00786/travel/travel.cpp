//杜吕俊泽 SN-J00786 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
string c1,s1;
string c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	int a=abs(int(s1[2])-65);
	int b=abs(int(s2[2])-65);
	if((a<=2 && b<=2) || (a>2 && b>2)){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	int x=abs(int(s1[2]));
	int y=abs(int(s2[2]));
	if(abs(x-y)==1 && ((s1[2]!='C' && s2[2]!='D') || (s1[2]!='D' && s2[2]!='C'))){
		cout<<"1";
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
}
