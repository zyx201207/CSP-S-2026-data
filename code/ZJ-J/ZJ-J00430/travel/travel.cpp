#include<bits/stdc++.h>
using namespace std;
string ff,fs,sf,ss;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ff>>fs>>sf>>ss;
	if(ff==sf)
	{
		if(fs[0]==ss[0]&&fs[1]==ss[1])
		{
			int f,s;
			f=(int)fs[2];
			s=(int)ss[2];
			if(f<=67&&s<=67||f>=68&&s>=68)
			{
				if(abs(f-s)==1)
				cout<<1111;
				else cout<<1110;
			}
			else cout<<1100;
		}
		else cout<<1000;
	}
	else cout<<0000;
	
	return 0;
}
