#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)cout<<1;
	else cout<<"0000",exit(0);
	if(s2.substr(0,2)==s4.substr(0,2))cout<<1;
	else cout<<"000",exit(0);
	if(s2[2]=='D')s2=s2.substr(0,2)+"E";
	if(s4[2]=='D')s4=s4.substr(0,2)+"E";
	if(s2>s4)swap(s2,s4);
	if(s4[2]<'D'||s2[2]>'D')cout<<1;
	else cout<<"00",exit(0);
	if(s4[2]-s2[2]==1)cout<<1;
	
	else cout<<0;
}
