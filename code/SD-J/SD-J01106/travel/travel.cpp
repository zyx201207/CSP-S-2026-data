#include<bits/stdc++.h>
using namespace std;
string sl,st,cl,ct,ssl,sst;
char a,b;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cl>>sl>>ct>>st;
	if(cl!=ct)
	{
		cout<<"0000";
		return 0;
	}
	else
	{	cout<<1;
		ssl=sl.substr(0,2);
		sst=st.substr(0,2);
		if(ssl!=sst)
		{
			cout<<"000";
			return 0;
		}
		else{
			cout<<1;
			a=sl[2];b=st[2];
			if(((int)a>=65&&(int)a<=67&&(int)b>=65&&(int)b<=67)||((int)a>=68&&(int)a<=70&&(int)b>=68&&(int)b<=70))
			{
				cout<<1;
				if((int)a-1==(int)b||(int)a+1==(int)b)
					cout<<1;
				else
					cout<<0;
			}
			else
			{
				cout<<"00";
				return 0;
			}
		}
	}
	
}
