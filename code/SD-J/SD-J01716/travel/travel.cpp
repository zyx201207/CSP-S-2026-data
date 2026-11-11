#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+9;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s1,s2,t1,t2;
	cin >> s1 >> s2 >> t1 >> t2;
	if(s1==t1) cout<<1;
	else 
	{
		cout<<"0000";
		return 0;
	}
	if(s2[1]==t2[1]) cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if(s2[2]>='A'&&s2[2]<='C'&&t2[2]>='A'&&t2[2]<='C' || s2[2]>='D'&&s2[2]<='E'&&t2[2]>='D'&&t2[2]<='E')cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if(s2[2]==t2[2]+1||t2[2]==s2[2]+1) cout<<1;
	else
	{
		cout<<"0";
		return 0;
	}
	return 0;
}

