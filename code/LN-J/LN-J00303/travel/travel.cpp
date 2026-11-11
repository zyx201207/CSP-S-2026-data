#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	bool q1=false,q2=false,q3=false;
	cin >>c1 >>s1 >>c2 >>s2;
	if(c1==c2){
		cout <<"1";
		q1=true;
	}else{
		cout <<"0000";
		return 0;
	}
	if(q1&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout <<"1";
		q2=true;
	}else{
		cout <<"000";
		return 0;
	}
	if(q2&&((s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A')||(s1[2]=='D'&&s2[2]=='F'||s2[2]=='D'&&s1[2]=='F'))){
		cout <<"1";
		q3=true;
	}else{
		cout <<"00";
		return 0;
	}
	if(q3&&((s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F'||s2[2]=='D'&&s1[2]=='F'))){
		cout <<"1";
	}else{
		cout <<"0";
	}
	//if(((s1[0]==s2[0]&&s1[1]==s2[1])&&(c1==c2)&&(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'))||((s1[0]==s2[0]&&s1[1]==s2[1])&&(c1==c2)&&(s1[2]=='D'&&s2[2]=='F'&&s1[2]=='F'&&s2[2]=='D'))&&((s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D')||(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B')))
	//cout <<1; else cout <<0;
	return 0;
}

