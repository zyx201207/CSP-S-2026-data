#include<bits/stdc++.h>
#define ll long long
using namespace std;
char w1,w2;
int a1,a2,b1,b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>w1>>b1>>b2>>w2;
	if(a1!=b1)
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(a2!=b2)
	{
		cout<<"000";
		return 0;
	}
	cout<<1;
	if((w1=='A'||w1=='B'||w1=='C')&&(w2=='D'||w2=='E'))
	{
		cout<<"00";
		return 0;
		
	}
	cout<<1;
	if(int(w1)-int(w2)==1||int(w1)-int(w2)==-1)
	{
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
} 
