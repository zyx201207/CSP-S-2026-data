#include<bits/stdc++.h>
using namespace std;
string cs1,cs2,zs1,zs2;
bool hang(char x)
{
	return x=='A'||x=='B'||x=='C'; 
}
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>cs1>>zs1>>cs2>>zs2;
if(cs1==cs2)
{
	cout<<1;
	if(zs1[0]==zs2[0]&&zs1[1]==zs2[1])
	{
		cout<<1;
		if(hang(zs1[2])==hang(zs2[2]))
		{
			cout<<1;
			if(abs(zs1[2]-zs2[2])==1)
			{
				cout<<1;
			}else cout<<0;
		}
		else cout<<0<<0;
	}
	else cout<<0<<0<<0;
}
	else
	{
		cout<<0<<0<<0<<0;
	}
return 0;
}

