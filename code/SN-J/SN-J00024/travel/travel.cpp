#include<bits/stdc++.h>
using namespace std;
  string a[1000],b[1000],c[1000],d[1000];
  	
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
  cin>>a[1000]>>b[1000]>>c[1000]>>d[1000];

 if(a[0][1]==c[0][1])
	{
		cout<<"1";
		
	}
	else
	{
		cout<<"0";
	}
	if(b[0][1]==d[0][1])
	{
		cout<<"1";
	}
	else
	{
		cout<<'0';
	}
	if(b[0][1]==d[0][1]||b[3]+'1'==d[3])
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(b[3]==d[3])
	{
		cout<<"1";
		
	}
	else{
		cout<<"0";
	}
	
	
	
	return 0;
}
