#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;
	int f1=0,f2=0,f3=0,f4=0;
	cin>>a>>b>>c>>d;
	if(a==c)	f1=1;
	if(f1==1&&b[0]==d[0]&&b[1]==d[1])	f2=1;
	if(f2==1&&(b[2]>='A'&&d[2]>='A'&&b[2]<='C'&&d[2]<='C'||b[2]>='D'&&d[2]>='D'&&b[2]<='F'&&d[2]<='F'))	f3=1;
	if(f3==1&&!(b[2]=='A'&&d[2]=='C'||b[2]=='C'&&d[2]=='A'))	f4=1;
	cout<<f1<<f2<<f3<<f4;
	return 0;
}

