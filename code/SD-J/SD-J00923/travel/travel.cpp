#include<bits/stdc++.h>
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define cfs cout<<fixed<<setprecision
#define ull unsigned long long
//#define i128 __int128
#define ll long long
#define endl '\n'
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	IO;
	string sa,sb,ta,tb;
	cin >> sa >> sb >> ta >> tb;
	if(sa==ta)
	{
		cout << 1;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	int x=(sb[0]-'0')*10+(sb[1]-'0');
	int y=(tb[0]-'0')*10+(tb[1]-'0');
//	cout << x << " " << y; 
	if(x==y)
	{
		cout << 1;
	}
	else
	{
		cout << "000";
		return 0;
	}
	x=sb[2]-'A';
	y=tb[2]-'A';
//	cout << x << " " << y;
	if((x<=2&&y<=2)||(x>2&&y>2))
	{
		cout << 1;
	}
	else
	{
		cout << "00";
		return 0;
	}
	if(abs(x-y)==1)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
//我常常追忆过去，生命瞬间定格在脑海，我揉捏天上的朵朵白云，饿啊我不会背。 
