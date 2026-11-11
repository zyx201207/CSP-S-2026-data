#include<bits/stdc++.h>
#define ll long long
using namespace std;
string cr,sr,cx,sx;
bool checkc()
{
	if(sr[2]>='A' && sr[2]<='C' && sx[2]>='A' && sx[2]<='C') return true;
	if(sr[2]>='D' && sr[2]<='F' && sx[2]>='D' && sx[2]<='F') return true;
	else return false;
}
bool checkt()
{
	if(sr[2]=='D' || sr[2]=='F') return true;
	else
	{
		if( (sr[2]=='A' && sx[2]=='C') || (sr[2]=='C' && sx[2]=='A')) return false;
		else return true;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>cr>>sr>>cx>>sx;
	if(cr[0]==cx[0] && cr[1]==cx[1])
	{
		cout<<"1";
		if(sr[0]==sx[0] && sr[1]==sx[1])
		{
			cout<<"1";
			if(checkc())
			{
				cout<<"1";
				if(checkt())
				{
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
