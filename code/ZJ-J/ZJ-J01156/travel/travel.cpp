#include<bits/stdc++.h>
using namespace std;
string c[10],s[10];
int a[10],b[10];
char x[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[1]>>s[1]>>c[2]>>s[2];
	a[1]=int(c[1][0]-'0')*10+int(c[1][1]-'0');
	a[2]=int(c[2][0]-'0')*10+int(c[2][1]-'0');
	if(a[1]==a[2])cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	x[1]=s[1][2],x[2]=s[2][2];
	b[1]=int(s[1][0]-'0')*10+int(s[1][1]-'0');
	b[2]=int(s[2][0]-'0')*10+int(s[2][1]-'0');
	if(b[1]==b[2])cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((x[1]<='C' && x[2]<='C') || (x[1]>='D' && x[2]>='D'))cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(int(x[1]-x[2]))==1)cout<<1;
	else cout<<"0";
	return 0;
}