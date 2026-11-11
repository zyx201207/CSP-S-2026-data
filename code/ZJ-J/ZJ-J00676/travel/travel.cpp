#include<iostream>
using namespace std;
int t1,t2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>t1>>s1>>t2>>s2;
	if(s1[2]=='D')s1[2]='E';
	if(s2[2]=='D')s2[2]='E';
	if(t1!=t2)cout<<"0000";
	else if(s1[0]!=s2[0]||s1[1]!=s2[1])cout<<"1000";
	else if(s1[2]<'D'&&s2[2]>'D'||s2[2]<'D'&&s1[2]>'D')cout<<"1100";
	else if(max((int)(s1[2]-s2[2]),(int)(s2[2]-s1[2]))!=1)cout<<"1110";
	else cout<<"1111";
	return 0;
}
