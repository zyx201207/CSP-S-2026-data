#include <bits/stdc++.h>
using namespace std;
int c_1,c_2;
string s_1,s_2;
bool q1,q2,q3,q4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2){
		q1=1;
	}
	int s_1_1=(s_1[0]-'0')*10+(s_1[1]-'0');
	int s_2_1=(s_2[0]-'0')*10+(s_2[1]-'0');
	char s_1_2=s_1[2],s_2_2=s_2[2];
	if(s_1_1==s_2_1&&q1==1){
		q2=1;
	}
	if(q2==1){
		if((s_1_2=='A'&&(s_2_2=='B'||s_2_2=='C'))||(s_1_2=='B'&&(s_2_2=='A'||s_2_2=='C'))||(s_1_2=='C'&&(s_2_2=='B'||s_2_2=='A'))||((s_1_2=='F'&&s_2_2=='D')||(s_1_2=='D'&&s_2_2=='F'))){\
			q3=1;
		}
	}
	if(q1==1&&q2==1&&q3==1){
		if(abs(s_1_2-s_2_2)==1){
			q4=1;
		}
	}
	cout<<q1<<q2<<q3<<q4;
}
