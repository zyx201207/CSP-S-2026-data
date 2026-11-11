//
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c1,c2;
	string s1,s2;
	bool a=1;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) a=1,c1=0,c2=0;
	else{
		cout<<"0000";
		return 0;
	}
	c1=int((s1[0]-'0')*10+(s1[1]-'0'));
	c2=int((s2[0]-'0')*10+(s2[1]-'0'));
	if(c1==c2) a=1;
	else{
		cout<<"1000";
		return 0; 
	}
	if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='E'&&s2[2]>='D'&&s2[2]<='E')) a=1;
	else{
		cout<<"1100";
		return 0;
	}
	if(abs(s1[2]-s2[2])==1){
		cout<<"1111";
		return 0;
	}
	else cout<<"1110";
	return 0;
}
