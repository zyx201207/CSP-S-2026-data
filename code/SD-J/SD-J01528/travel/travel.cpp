#include<bits/stdc++.h>
#define int long long
using namespace std;
string ca,sa,cb,sb;
bool a,b,c,d;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>ca>>sa>>cb>>sb;
	if(ca[0]==cb[0]&&ca[1]==cb[1]) a=1;
	if(sa[0]==sb[0]&&sa[1]==sb[1]&&a==1) b=1;
	if(b==1)
	{
		if((sa[2]=='F'&&sb[2]=='D')||(sb[2]=='F'&&sa[2]=='D')) {c=1;d=1;}
		else if((sa[2]=='A'&&sb[2]=='B')||(sb[2]=='A'&&sa[2]=='B')) {c=1;d=1;}
		else if((sa[2]=='B'&&sb[2]=='C')||(sb[2]=='B'&&sa[2]=='C')) {c=1;d=1;}
		else if((sa[2]=='A'&&sb[2]=='C')||(sb[2]=='A'&&sa[2]=='C')) c=1;
	}
	cout<<a<<b<<c<<d;
	return 0;
}
