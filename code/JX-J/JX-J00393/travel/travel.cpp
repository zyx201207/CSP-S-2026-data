#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char e,f;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>e>>c>>d>>f;
	if(a==c) cout<<1; else
	{
		cout<<"0000";
		return 0;
	} 
	if(b==d) cout<<1; else 
	{
		cout<<"000";
		return 0;
	}
	if(((e=='A'||e=='B'||e=='C')&&(f=='A'||f=='B'||f=='C'))||((e=='F'||e=='D')&&(f=='F'||f=='D'))) cout<<1;
	else {cout<<"00";return 0;}
	if(abs(int(e-f))==1&&((e!='F'&&f!='D')||(e!='D'&&f!='F'))) cout<<1;
	else cout<<0;
	return 0;
}
