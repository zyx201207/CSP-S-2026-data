#include<bits/stdc++.h>
using namespace std;
string _s1,_s2,s3,s4;
int _c1,_c2,_p1,_p2;
char _d1,_d2;
int d_d1,d_d2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> _s1 >> _s2 >> s3 >> s4;
	if(_s1[0] == '0')
	{
		_c1 = _s1[1]-'0';
	}
	else
	{
		_c1 = (_s1[0]-'0')*10+_s1[1]-'0';
	}
	if(s3[0] == '0')
	{
		_c2 = s3[1]-'0';
	}
	else
	{
		_c2 = (s3[0]-'0')*10+s3[1]-'0';
	}
	_d1 = _s2[2];
	if(_s2[0] == '0')
	{
		_p1 = _s2[1]-'0';
	}
	else
	{
		_p1 = (_s2[0]-'0')*10+_s2[1]-'0';
	}
	_d2 = s4[2];
	if(s4[0] == '0')
	{
		_p2 = s4[1]-'0';
	}
	else
	{
		_p2 = (s4[0]-'0')*10+s4[1]-'0';
	}
	if(_c1 == _c2)
		cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
		
	if(_p1 == _p2)
		cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
		
	if(_d1 == 'F'||_d1 == 'D')
		d_d1 = 1;
	else
		d_d1 = 0;
	if(_d2 == 'F'||_d2 == 'D')
		d_d2 = 1;
	else
		d_d2 = 0;
	if(d_d1 == d_d2)
		cout<<1;
	else 
	{
		cout<<"00";
		return 0;
	}
		
	if(d_d1 == d_d2&&d_d1 == 1)
	{
		cout<<1;
		return 0;
	}
	if(_d1=='B'||_d2 == 'B')
		cout<<1;
	else
		cout<<0;
	return 0;
	//reverse;
}
