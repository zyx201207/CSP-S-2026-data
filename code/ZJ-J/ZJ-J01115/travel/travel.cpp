#include<bits/stdc++.h>
using namespace std;
bool f;
int n1,n2,k1,k2;
string s1,s2,ss1,ss2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>ss1>>s2>>ss2;
	f=true;
	if(ss1[2]=='A')n1=1;
	if(ss1[2]=='B')n1=2;
	if(ss1[2]=='C')n1=3;
	if(ss1[2]=='D')n1=4;
	if(ss1[2]=='F')n1=5;
	if(n1<=3)k1=0;
	else k1=1;
	if(ss2[2]=='A')n2=1;
	if(ss2[2]=='B')n2=2;
	if(ss2[2]=='C')n2=3;
	if(ss2[2]=='D')n2=4;
	if(ss2[2]=='F')n2=5;
	if(n2<=3)k2=0;
	else k2=1;
	if(f==true&&s1==s2)cout<<1;
	else {
		cout<<0;
		f=false;
	}
	if(f==true&&ss1[0]==ss2[0]&&ss1[1]==ss2[1])cout<<1;
	else {
		cout<<0;
		f=false;
	}
	if(f==true&&k1==k2)cout<<1;
	else {
		cout<<0;
		f=false;
	}
	if(f==true&&abs(n1-n2)==1)cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
