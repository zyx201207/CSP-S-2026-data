#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a-c==0&&c-a==0)
	{
	cout<<"1";
	}
	else
	{
	cout<<"0";
	}
	if(b-d<5,d-b<5,b-d!=0,d-b!=0,d!=b,b!=d)
	{
	cout<<"1";
	 } 
	 else
	 {
	cout<<"0";
	 }
	if(b-d<3,d-b<3,b-d<2,d-b<2,d!=b,b!=d)
	{
		cout<<"1";
	 } 
	 else
	 {
	 	cout<<"0";
	 }
	 	if(b+1==d,d+1==b)
	{
		cout<<"1";
	 } 
	 else
	 {
	 	cout<<"0";
	 }
	 return 0;
}
