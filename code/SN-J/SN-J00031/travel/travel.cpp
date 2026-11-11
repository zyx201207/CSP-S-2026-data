#include<bits/stdc++.h>
using namespace std;
string a,b,aa,bb;
char ao,at;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> a >> aa >> b >> bb;
	if(a==b)
	{
		cout << 1;
		ao=aa[2];
		at=bb[2];
		aa[2]='0';
		bb[2]='0';
		if(aa==bb)
		{
			cout << 1;
			if(((ao=='A' or ao=='B' or ao=='C') and (at=='A' or at=='B' or at=='C')) or ((ao=='D' or ao=='F') and (at=='D' or at=='F')))
			{
				cout << 1;
				if(ao=='A' and at=='C')
				{
					cout << 0;
				}
				else
				{
					cout << 1;
				}
			}
			else
			{
				cout << "00";
			}
		}
		else
		{
			cout << "000";
		}
	}
	else
	{
		cout << "0000";
	}
	return 0;
} 
