#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	cout<<"1";
	else
	cout<<"0";
	if(s1[3]==s2[3])
	cout<<"1";
	else
	cout<<"0";
	if(c2==c1)
	cout<<"1";
	else
	cout<<"0";
	if(s2[3]==s1[3])
	cout<<"1";
	else
	cout<<"0";
    return 0;       
}