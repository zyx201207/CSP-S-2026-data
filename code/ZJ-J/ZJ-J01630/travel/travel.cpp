#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	char ch1=b[2],ch2=d[2];
	bool b1=a==c,b2=(b.substr(0,2)==d.substr(0,2))&&b1,b3=((ch1>'C'&&ch2>'C')||(ch1<='C'&&ch2<='C'))&&b2,b4=b3&&(ch1-'C'>0?1:(ch1=='B'||ch2=='B'?1:0));
	cout<<b1<<b2<<b3<<b4;
	return 0;
}