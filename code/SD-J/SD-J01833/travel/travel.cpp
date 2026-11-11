#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool b=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2&&b==1){
		cout<<1;
	}
	else {
		cout<<0;
		b=0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&b==1){
		cout<<1;
	}
	else {
		cout<<0;
		b=0;
	}
	if((s1[2]!='F'&&s1[2]!='D'&&s2[2]!='F'&&s2[2]!='D'||((s1[2]=='F'||s1[2]=='D')&&(s2[2]=='F'||s2[2]=='D')))&&b==1){
		cout<<1;
	}
	else {
		cout<<0;
		b=0;
	}
	if(abs(s1[2]-s2[2])==1&&b==1){
		cout<<1;
	}
	else {
		cout<<0;
		b=0;
	}
	return 0;
}
