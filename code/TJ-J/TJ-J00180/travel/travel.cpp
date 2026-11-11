#include <bits/stdc++.h>
using namespace std;
long long a,b,ai,bi,ac,bc;
string aa,bb,az,bz;
int main()
{
	//==============================================
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> aa >> az >> bb >> bz;
	//
	a+=(aa[0]-'0')*10;
	a+=aa[1]-'0';
	b+=(bb[0]-'0')*10;
	b+=bb[1]-'0';
	if(a==b)
	{
		cout << "1";
	}
	else
	{
		cout << "0000";
		return 0;
	}
	//
	a=(az[0]-'0')*10;
	a+=az[1]-'0';
	b=(bz[0]-'0')*10;
	b+=bz[1]-'0';
	if(a==b)
	{
		cout << "1";
	}
	else
	{
		cout << "000";
		return 0;
	}
	//
	if((az[2]<='C' && bz[2]<='C') || (az[2]>='D' && bz[2]>='D'))
	{
		cout << "1";
	}
	else
	{
		cout << "00";
		return 0;
	}
	//
	if((abs(az[2]-bz[2])<=1) || (az[2]=='D' && bz[2]=='F') || (az[2]=='F' && bz[2]=='D'))
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	return 0;
} 
