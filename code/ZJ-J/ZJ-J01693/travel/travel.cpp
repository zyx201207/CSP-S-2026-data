#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int a,a1,b,b1;
	char A,B;
	cin>>a>>a1>>A>>b>>b1>>B;
	if(a == b) cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	}
	if(a1 == b1) cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	}
	if(((A == 'A'||A == 'B'||A == 'C') && (B == 'A'||B == 'B'||B == 'C')) || ((A == 'D'||A == 'F') && (B == 'D'||B == 'F')))
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if((int)A - (int)B == 1 || (int)B - (int)A == 1)
	{
		cout<<"1";
	}
	else 
	{
		cout<<"0";
	}
	return 0;
}
