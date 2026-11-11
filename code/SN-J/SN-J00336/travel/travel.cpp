#include<bits/stdc++.h>
using namespace std;
int main(){	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a;
	string b;
	string c;
	string n;
	cin>>a>>b>>c>>n;
	if(a[1]!=c[1]||a[0]!=c[0]) cout<<0000;
	else if(a==c&&b[1]==n[1]&&b[0]==n[0]&&abs(b[2]-n[2])==1&&b[2]!='D'&&n[2]!='C'&&b[2]!='C'&&n[2]!='D') cout<<1111;
	else if(a==c&&b[1]==n[1]&&b[0]==n[0]&&abs(b[2]-n[2])!=1||a==c&&b[1]==n[1]&&b[0]==n[0]&&b[2]=='C'&&n[2]=='D'||a==c&&b[1]==n[1]&&b[0]==n[0]&&b[2]=='D'&&n[2]=='C') cout<<1110;
	else if(b[2]=='D'&&n[2]=='C'||b[2]=='C'&&n[2]=='D') cout<<1100;
	else if(b[0]==n[0]&&a==c&&b[2]-n[2]!=1||b[1]==n[1]&&a==c&&b[2]-n[2]!=1) cout<<1100;
	else if(a==c&&b[1]!=n[1]||a==c&&b[0]!=n[0])cout<<1000;
	return 0;
}
