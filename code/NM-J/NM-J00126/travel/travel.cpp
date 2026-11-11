#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char q1=s1[2],q2=s2[2];
	//cout<<q1<<" "<<q2<<endl;
	bool z1=0,z2=0,z3=0,z4=0;
	if(c1==c2)z1=1;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&z1==1)z2=1;
	if(z2==1&&((q1=='A'&&q2=='B')||(q2=='A'&&q1=='B')||(q1=='A'&&q2=='C')||(q2=='A'&&q1=='C')||(q1=='B'&&q2=='C')||(q2=='B'&&q1=='C')||(q1=='F'&&q2=='D')||(q2=='F'&&q1=='D')))z3=1;
	if(abs(q1-q2)==1&&z3==1)z4=1;
	cout<<z1<<z2<<z3<<z4;
	return 0; 
} 
