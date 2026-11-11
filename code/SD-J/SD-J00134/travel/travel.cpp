#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fst ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int P=998244353;
const long long INF=0x3f3f3f3f3f3f3f3f;
const int N=1e6+10,M=2e6+10;

string s1,s2,c1,c2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<'1';
		string s=s1.substr(0,2);
		string t=s2.substr(0,2);
		if(s==t)
		{
			cout<<'1';
			bool a=(s1[2]<='C');
			bool b=(s2[2]<='C');
			if(a==b)
			{
				cout<<'1';
				if(a==0)
				{
					cout<<'1';
				}
				else if(abs(0ll+s1[2]-s2[2])<=1)
				{
					cout<<'1';
				}
				else
				{
					cout<<'0';
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
