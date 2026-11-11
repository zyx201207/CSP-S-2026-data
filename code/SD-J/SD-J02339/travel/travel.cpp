#include<bits/stdc++.h>
using namespace std;
bool f1=false,f2=false,f3=false;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	cout<<1;
	else
	cout<<0;
	f1=false;
	string p1="";
	p1+=b[0];
	p1+=b[1];
	string p2="";
	p2+=d[0];
	p2+=d[1]; 
	
	return 0;
}
