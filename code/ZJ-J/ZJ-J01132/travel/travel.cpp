#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll j[1000];
string a,b,c,d;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	j['A']=j['B']=j['C']=1;
	j['D']=j['F']=0;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<1;
		if(b.substr(0,2)==d.substr(0,2))
		{
			cout<<1;
			if(j[b[2]]==j[d[2]])
			{
				cout<<1;
				if(b[2]==0) cout<<1;
				else if(abs(b[2]-d[2])==1) cout<<1;
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else
	{
		cout<<"0000";
	}
}
