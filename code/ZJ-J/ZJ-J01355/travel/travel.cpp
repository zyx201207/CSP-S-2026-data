#include <bits/stdc++.h>
using namespace std;
int cr,cx,srys,sxys;
string sr,sx;
bool ok[6];
char m[3],n[2];
int ys(char l)
{
	if (l=='A') return 0;
	if (l=='B') return 1;
	if (l=='C') return 2;
	if (l=='D') return 20;
	if (l=='F') return 21;
	return -1;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	srys=ys(sr[2]);
	sxys=ys(sx[2]);
	ys(sx[2]);
	if (cr==cx) cout<<'1';
	else
	{
		cout<<'0';
		cout<<'0';
		cout<<'0';
		cout<<'0';
		return 0;
	}
	if (sr[0]==sx[0]&&sr[1]==sx[1]) cout<<'1';
	else 
	{
		cout<<'0';
		cout<<'0';
		cout<<'0';
		return 0;
	}
	if (((srys+sxys)<=3)||((srys+sxys)==41)) cout<<'1';
	else 
	{
		cout<<'0';
		cout<<'0';
		return 0;
	}
	if (((srys+sxys)==1)||((srys+sxys)==3)||((srys+sxys)==41)) cout<<'1';
	else cout<<'0';
	return 0;
}
