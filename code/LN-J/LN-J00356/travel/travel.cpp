#include<bits/stdc++.h>
const int N=5;
using namespace std;
char ads2[N];
char ads4[N];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int sum=0;
	string a1,a3;
	cin>>a1;
	for(int i=0;i<=2;i++)
	{
		cin>>ads2[i];
	}
	cin>>a3;
	for(int i=0;i<=2;i++)
	{
		cin>>ads4[i];
	}
	if(a1==a3) cout<<"1";
	if(a1!=a3) 
	{
		 cout<<"0000";
		 return 0;
	}
	for(int i=0;i<=1;i++)
	{
		if(ads2[i]!=ads4[i]) 
		{
			cout<<"000";
			return 0;
		}
		else if(ads2[i]==ads4[i]) sum++;
	}
	if(sum==2) cout<<"1";
	if(ads2[2]>='A'&&ads2[2]<='C'&&ads4[2]>='A'&&ads4[2]<='C') cout<<"1";
	else if(ads2[2]>='D'&&ads2[2]<='F'&&ads4[2]>='D'&&ads4[2]<='F') cout<<"1";
	else 
	{
		cout<<"00";
		return 0;
	}
	if(ads2[2]=='A'&&ads4[2]=='B') cout<<"1";
	else if(ads2[2]=='B'&&ads4[2]=='A') cout<<"1";
	else if(ads2[2]=='B'&&ads4[2]=='C') cout<<"1";
	else if(ads2[2]=='C'&&ads4[2]=='B') cout<<"1";
	else if(ads2[2]=='D'&&ads4[2]=='F') cout<<"1";
	else if(ads2[2]=='F'&&ads4[2]=='D') cout<<"1";
	else cout<<"0";
	return 0;
}
