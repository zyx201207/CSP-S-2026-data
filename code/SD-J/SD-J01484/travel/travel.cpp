#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
char pai1,pai2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	int wei1=0,wei2=0;
	for(int i=0;i<2;i++)
	{
		wei1*=10;
		wei2*=10;
		wei1+=s1[i]-'0';
		wei2+=s2[i]-'0';
	}
	pai1=(char)s1[2];
	pai2=(char)s2[2];
	if(c1==c2)
	{
		cout<<'1';
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(wei1==wei2)
	{
		cout<<'1';
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(pai1=='A'||pai1=='B'||pai1=='C')
	{
		if(pai2=='A'||pai2=='B'||pai2=='C')
		{
			cout<<'1';
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else if(pai1=='D'||pai1=='F')
	{
		if(pai2=='D'||pai2=='F')
		{
			cout<<"11";
			return 0;
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(pai2-pai1)==1)
	{
		cout<<'1';
	}
	else
	{
		cout<<'0';
	}
	return 0;
}
