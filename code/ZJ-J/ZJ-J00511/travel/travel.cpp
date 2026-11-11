#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel1.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ax,az1,az2,bx,bz1,bz2;
	string s;
	cin>>ax;
	cin>>s;
	az1=(s[0]-'0')*10+s[1]-'0';
	az2=int(s[2]);
	cin>>bx;
	cin>>s;
	bz1=(s[0]-'0')*10+s[1]-'0';
	bz2=int(s[2]);
	bool f1,f2,f3,f4;
	f1=f2=f3=f4=0;
	f1=(ax==bx);
	f2=(f1&&(az1==bz1));
	f3=(f2&&(('A'<=az2&&az2<='C'&&'A'<=bz2&&bz2<='C')||('D'<=az2&&az2<='F'&&'D'<=bz2&&bz2<='F')));
	f4=(f3&&(abs(int(az2-bz2))==1));
	cout<<f1<<f2<<f3<<f4;
	return 0;
}