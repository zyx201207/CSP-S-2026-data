#include<bits/stdc++.h> 
#define int long long
#define endl "\n"
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	bool p=0;
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<1;
		p=1;
	}
	else
	{
		cout<<0;
	}
	bool f=0;
	if(p&&((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='E'&&s2[2]>='D'&&s2[2]<='E')))
	{
		cout<<1;
		f=1;
	}
	else
	{
		cout<<0;
	}
	if(f&&abs(s1[2]-s2[2])==1)
	{
		cout<<1;
	}
	else cout<<0;
	return 0;
}
