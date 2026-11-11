#include <bits/stdc++.h>
using namespace std;
int cx,cy;
string sx,sy;
int num,cnt;
char a[] = {'A','B','C'};
char b[] = {'D','F'};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx>>sx>>cy>>sy;
	if(cx != cy)
	{
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
	}
	
	if(sx[0] == sy[0]&&sx[1] == sy[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	
	for(int i = 0;i<3;i++)
	{
		if(sx[2] == a[i]){
			num=1;
		}
	}
	
	for(int i = 0;i<2;i++)
	{
		if(sx[2] == b[i]){
			num=2;
		}
	}
	
	for(int i = 0;i<3;i++)
	{
		if(sy[2] == a[i]){
			cnt=1;
		}
	}
	
	for(int i = 0;i<2;i++)
	{
		if(sy[2] == b[i]){
			cnt=2;
		}
	}
	if(num == cnt){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	
	if(sx[2] == 'A'&&sy[2] == 'B')
	{
		cout<<"1";
		return 0;
	}
	if(sx[2] == 'B'&&sy[2] == 'C')
	{
		cout<<"1";
		return 0;
	}
	if(sx[2] == 'D'&&sy[2] == 'F')
	{
		cout<<"1";
		return 0;
	}
	if(sx[2] == 'F'&&sy[2] == 'D')
	{
		cout<<"1";
		return 0;
	}
	if(sx[2] == 'C'&&sy[2] == 'B')
	{
		cout<<"1";
		return 0;
	}
	if(sx[2] == 'B'&&sy[2] == 'A')
	{
		cout<<"1";
		return 0;
	}
	cout<<"0";
	return 0;
}





