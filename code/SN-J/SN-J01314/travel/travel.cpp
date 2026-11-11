#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	string ca, cb, sa, sb;
	cin>>ca>>sa>>cb>>sb;
	if(ca!=cb)
	{
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(!(sa[0]==sb[0]&&sa[1]==sb[1]))
	{
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if(!(((sa[2]-'A'<=2) && (sb[2]-'A'<=2)) || ((sa[2]-'A'>2) && (sb[2]-'A'>2))) )
	{
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(sa[2]-sb[2]==1 || sa[2]-sb[2]==-1) 
	{
		cout<<"1";
		return 0;
	}
	cout<<"0";
	return 0;
}


