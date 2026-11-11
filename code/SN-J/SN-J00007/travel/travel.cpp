#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);
	int a,b,c,d;
	cin>>a>>c>>b>>d;
	if(a%1==b%1)
	cout<<"1";
	else
	cout<<"0";
	if(c==d)
	cout<<"1";
	else
	cout<<"0";
	if(c+d<=23||d+c>=23)
	cout<<"1";
	else
	cout<<"0";
	if(c-d<=1||d-c<=1)
	cout<<"1";
	else
	cout<<"0";
	return 0;
}
