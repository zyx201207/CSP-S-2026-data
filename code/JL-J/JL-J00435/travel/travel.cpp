#include<bits/stdc++.h>
using namespace std;
string ca,cb,sa,sb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb)
	{
	       	cout<<1;
		if(sa[0]==sb[0]&&sa[1]==sb[1])
		{
			cout<<1;
			if(sa[2]>'C'&&sb[2]>'C')
				cout<<1<<1;
			else if(sa[2]<='C'&&sb[2]<='C'){
				cout<<1;
				if(abs(sa[2]-sb[2])==1)
					cout<<1;
				else
					cout<<0;
			}
			else
				cout<<0<<0;
		}
		else
			cout<<0<<0<<0;
	}
	else
		cout<<0<<0<<0<<0;
	return 0;
}
