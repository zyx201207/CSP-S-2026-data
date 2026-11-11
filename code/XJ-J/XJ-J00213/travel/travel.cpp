#include<bits/stdc++.h>
using namespace std;
string a[100000];
int main()
{
freopen("travel.in","w",stdin);
freopen("travel.out","r",stdout);
cin>>a[100000];
if(a[0]==a[6]&&a[1]==a[7])
{
	cout<<"1";
}
else
{
	cout<<"0";
}
if(a[3]==a[9]&&a[4]==a[10])
{
	cout<<"1";
}
else
{
	cout<<"0";
}
if(a[5]+1=a[11]||a[11]+1==a[5])
{
	cout<<"1";
}
else
{
	cout<<"0";
}

return 0;
}
