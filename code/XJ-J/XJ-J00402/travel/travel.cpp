#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int af3_=0,af12_=0,af21_=0,af3_a=0;
bool zwxl(string a,string b)
{
	if(a[0]=='B') return (b[0]=='C'||b[0]=='A');
	if(b[0]=='B') return (a[0]=='C'||a[0]=='A');
	
	if(a[0]=='F')return (b[0]=='D');
	if(b[0]=='F')return (a[0]=='D');
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)af3_=1;
	if(af3_ ==1&&stod(s1.substr(0,2))==stod(s2.substr(0,2)))af12_=1;
	if(af3_==1&&af12_==1&&((s1.substr(2,1)<="C"&&s2.substr(2,1)<="C")||(s1.substr(2,1)>"C"&&s2.substr(2,1)>"C")))af21_=1;
	if(af3_==1&&af12_==1&af21_==1&&zwxl(s1.substr(2,1),s2.substr(2,1)))af3_a=1;
	cout<<af3_<<af12_<<af21_<<af3_a;
	return 0;
}
