#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool flag=false;
char a[6]={'A','B','C','D','F'};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else 
	{
		cout<<"0000";
		return 0;
	}
	int pai1=s1[0]*10+s1[1];
	int pai2=s2[0]*10+s2[1];
	if(pai1==pai2) cout<<1;
	else 
	{
		cout<<"000";
		return 0;
	}
	char f1=s1[2];
	char f2=s2[2];
	if(f1>='A'&&f1<='C'&&f2>='A'&&f2<='C') 
	{
		cout<<1;
	}
	else if(f1>='D'&&f1<='F'&&f2>='D'&&f2<='F') 
	{
		cout<<1;
	}
	else 
	{
		cout<<"00";
		return 0;
	}
	if((a[f1-'A'+1]==f2)||(a[f2-'A'+1]==f1))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
 } 