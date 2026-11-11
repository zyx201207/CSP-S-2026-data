#include<bits/stdc++.h>
using namespace std;
bool check(char q1,char q2){
	if(q1=='A'&&q2=='B') return true;
	if(q1=='B'&&q2=='A') return true;
	if(q1=='B'&&q2=='C') return true;
	if(q1=='C'&&q2=='B') return true;
	if(q1=='D'&&q2=='F') return true;
	if(q1=='F'&&q2=='D') return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;string s1,s2;
	int a1=0,a2=0,a3=0,a4=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			a2=1;
			if((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'C')){
				a3=1;
				if(check(s1[2],s2[2])){
					a4=1;
				}
			}
		}
	}
	cout<<a1<<a2<<a3<<a4;
	return 0;
}

