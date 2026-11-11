#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool f1,f2,f3,f4;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> a >> b >> c >> d;
	if(a==c)f1=1;
	if(b[0]==d[0]&&b[1]==d[1]&&f1==1)f2=1;
	char x=b[2],y=d[2];
	if(((x>='A'&&x<='C'&&y>='A'&&y<='C')||((x=='D'||x=='F')&&(y=='D'||y=='F')))&&f2==1)
		f3=1;
	if(f3==1)
	{
		if(x=='D'||x=='F')f4=1;
		else if(abs(x-y)==1)f4=1;
	}
	cout << f1 << f2 << f3 << f4;
    return 0;
}
