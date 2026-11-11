#include<bits/stdc++.h>
using namespace std;
string a[5]={"A","B","C","D","F"};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1,s1,c2,s2;
	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
string len1=s1.substr(0,2);
string len2=s2.substr(0,2);
string len3=s1.substr(2,1);
string len4=s2.substr(2,1);

if(len1==len2)
{
	cout<<"1";
}
else
{
	cout<<"0";
}
if(len1==len2&&len3<=a[2]&&len3>=a[0]&&len4<=a[2]&&len4>=a[0]||len1==len2&&len3<=a[4]&&len3>=a[3]&&len4<=a[4]&&len4>=a[3])
{
	cout<<"1";
}
else
{
	cout<<"0";
}
if(abs(len3-len4)==1&&len3<=a[4]&&len4<=a[4]||abs(len3-len4)==2&&len3>=a[3]&&len4>=a[3])
{
	cout<<"1";
}
else
{
	cout<<"0";
}
return 0;
	
}
