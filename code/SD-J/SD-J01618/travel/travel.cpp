#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char f(char c)
{
	if(c=='B'||c=='C') return 'A';
	if(c=='E') return 'D';
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int sa,sb,xa,xb;
	char ca,cb;
	bool p=1;
	cin>>sa>>xa>>ca>>sb>>xb>>cb;
	if((ca=='A'||ca=='C')&&(cb=='A'||cb=='C')) p=0;
	ca=f(ca);
	cb=f(cb);
	if(sa!=sb) cout<<"0000";
	else
	{
		cout<<1;
		if(xa!=xb) cout<<"000";
		else{
			cout<<1;
			if(ca!=cb) cout<<"00";
			else {
				cout<<1;
				if(p) cout<<1;
				else cout<<0;
			}
		}
	}
	return 0;
}
//02 01A 02 01B
//1111
//02 01C 02 01A
//1110
