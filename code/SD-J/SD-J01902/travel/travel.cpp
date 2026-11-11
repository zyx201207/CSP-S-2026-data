#include<bits/stdc++.h>
#define int long long
using namespace std;
int c1,s1,c2,s2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string t1,t2;
	cin>>c1>>s1>>t1>>c2>>s2>>t2;
	if(c1==c2) cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1==s2) cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if((t1=="D"||t1=="F")==(t2=="D"||t2=="F")) cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if((t1=="D"||t1=="F")) cout<<1;
	else if(t1!="A"&&t2!="A"||t1!="C"&&t2!="C") cout<<1;
	else cout<<0;
	return 0;
}
