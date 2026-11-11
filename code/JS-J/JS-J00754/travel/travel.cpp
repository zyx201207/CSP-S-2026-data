#include<bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

bool check1(char x,char y)
{
	if(x>='D' and y>='D') return 1;
	if(x<='C' and y<='C') return 1;
	return 0;
}
bool check2(char x,char y)
{
	if(abs(x-y)==1) return 1;
	return 0;
}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char e,f;
	cin>>a>>b>>e>>c>>d>>f;
	if(e=='F') e='E';
	if(f=='F') f='E';
	
	if(a==c)
	{
		cout<<1;
		if(b==d)
		{
			cout<<1;
			if(check1(e,f))
			{
				cout<<1;
				if(check2(e,f)) cout<<1;
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
