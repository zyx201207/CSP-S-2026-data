#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b;
string aa,bb;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>aa>>b>>bb;
	if(a==b)
	{
		cout<<"1";
		if(aa[0]==bb[0]&&aa[1]==bb[1])
		{
			cout<<"1";
			int ta,tb,ca,cb;
			if(aa[2]=='A') ta=1,ca=1;
			if(aa[2]=='B') ta=2,ca=1;
			if(aa[2]=='C') ta=3,ca=1;
			if(aa[2]=='D') ta=5,ca=2;
			if(aa[2]=='E') ta=6,ca=2;
			if(bb[2]=='A') tb=1,cb=1;
			if(bb[2]=='B') tb=2,cb=1;
			if(bb[2]=='C') tb=3,cb=1;
			if(bb[2]=='D') tb=5,cb=2;
			if(bb[2]=='E') tb=6,cb=2;
			if(ca==cb)
			{
				cout<<"1";
				int tmp=abs(ta-tb);
				if(tmp==1)
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
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

