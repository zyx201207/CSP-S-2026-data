#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) s+='1';
	else s+='0';
	string b2,d2;
	int b3=b[2]-'A'+1,d3=d[2]-'A'+1;
	b2+=b[0];
	b2+=b[1];
	d2+=d[0];
	d2+=d[1];
	if(b2==d2&&a==c) s+='1';
	else s+='0';
	if(b2==d2&&a==c&&(((b3>=1&&b3<=3)&&(d3>=1&&d3<=3))||((b3>=4&&b3<=6)&&(d3>=4&&d3<=6)))) s+='1';
	else s+='0';
	if(b2==d2&&a==c&&((b3>=1&&b3<=3)&&(d3>=1&&d3<=3))&&(abs(b3-d3)==1)) s+='1';
	else if(b2==d2&&a==c&&((b3>=4&&b3<=6)&&(d3>=4&&d3<=6))) s+='1';
	else s+='0';
	cout<<s;
	return 0;
}
