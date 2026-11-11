#include<iostream>
#include<cstdio>
using namespace std;
int cara,carb;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cara>>a>>carb>>b;
	if(cara==carb) cout<<1;
	else cout<<0;
	int ra=(a[0]-'0')*10+(a[1]-'0');
	int rb=(b[0]-'0')*10+(b[1]-'0');
	if(ra==rb&&cara==carb) cout<<1;
	else cout<<0;
	if(cara==carb&&ra==rb&&(a[2]>='A'&&a[2]<='C'&&b[2]>='A'&&b[2]<='C'||a[2]>='D'&&a[2]<='F'&&b[2]>='D'&&b[2]<='F')) cout<<1;
	else cout<<0;
	if(cara==carb&&ra==rb&&(a[2]=='A'&&b[2]=='B'||(a[2]=='B'&&b[2]=='A'||a[2]=='B'&&b[2]=='C')||a[2]=='C'&&b[2]=='B'||a[2]=='D'&&b[2]=='F'||a[2]=='F'&&b[2]=='D')) cout<<1;
	else cout<<0;
	return 0;
}
