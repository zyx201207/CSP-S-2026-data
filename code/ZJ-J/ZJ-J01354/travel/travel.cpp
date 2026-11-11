#include <bits/stdc++.h>
using namespace std;
bool check1(string a,string b) {
	return (a[0]==b[0]&&a[1]==b[1]);
}
bool check2(string a,string b) {
	bool k1,k2;
	if(a[2]>='A'&&a[2]<='C')k1=0;
	else k1=1;
	if(b[2]>='A'&&b[2]<='C')k2=0;
	else k2=1;
	return k1==k2;
}
bool check3(string a,string b) {
	if(a[2]>='A'&&a[2]<='C'&&b[2]>='A'&&b[2]<='C')return abs(a[2]-b[2])==1;
	else return abs(a[2]-b[2])==2;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2,ans;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		ans+='1';
		if(check1(s1,s2)) {
			ans+='1';
			if(check2(s1,s2)) {
				ans+='1';
				if(check1(s1,s2)&&check2(s1,s2)&&check3(s1,s2))ans+='1';
				else ans+='0';
			} else for(int i=1; i<=2; i++)ans+='0';
		} else for(int i=1; i<=3; i++)ans+='0';
	} else for(int i=1; i<=4; i++)ans+='0';
	cout<<ans;
	return 0;
}