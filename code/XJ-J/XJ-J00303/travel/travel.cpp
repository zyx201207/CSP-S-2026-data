#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("travel.in ","r",stdin);
		freopen("travel.out ","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;


		if(c1==c2)
		{
			cout<<"1";
		}
		else{
			cout<<"0";
		}
		if(s1.substr(0,1)==s2.substr(0,1))
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
		if(s1!=s2&&s1.substr(0,1)==s2.substr(0,1))
	
		{
		cout<<"1";	
		}
		else{
			cout<<"0";
		}

	cout<<"1";

	return 0;
}