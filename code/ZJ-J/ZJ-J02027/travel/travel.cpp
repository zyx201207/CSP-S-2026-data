#include<bits/stdc++.h>
using namespace std;
char a[18];
int main(){
	freopen("traval.in","r",stdin);
	freopen("traval.out","w",stdout);
	for(int i=1;i<=10;i++)
	{
		cin >> a[i];
	}
	if(a[1]==a[6]&&a[2]==a[7])
	{
		cout << 1;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	if(a[3]==a[8]&&a[4]==a[9])
	{
		cout << "1";
	}
	else
	{
		cout << "000";
		return 0;
	}
	int b,c;
	if(a[5]=='F'||a[5]=='D')
	{
		b=1;
	}
	else
	{
		b=2;
	}
	if(a[10]=='F'||a[10]=='D')
	{
		c=1;
	}
	else
	{
		c=2;
	}
	if(b==c)
	{
		cout << "1";
	}
	else
	{
		cout << "00";
		return 0;
	}
	if(b==1)
	{
		cout << "1";
	}
	else
	{
		if(a[5]=='B'||a[10]=='B')
		{
			cout << "1";
		}
		else
		{
			cout << "0";
		}
	}
	return 0;
} 
