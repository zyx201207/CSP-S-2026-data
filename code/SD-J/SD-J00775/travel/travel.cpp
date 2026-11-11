#include<bits/stdc++.h>
#define int long long
using namespace std;
string c,s,cc,ss;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc)cout<<1;
	else 
	{
		cout<<"0000";
		return 0;
	}
	
	if(s[0]==ss[0] && s[1]==ss[1])
		cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	
	if((s[0]==ss[0] && s[1]==ss[1]) && ((s[2]<'D'&&ss[2]<'D')||(s[2]>='D'&&ss[2]>='D')))
		cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	
	cout<<( (s[2]+1==ss[2] || s[2]-1==ss[2]) && (!((s[2]=='C' && ss[2]=='D') || (s[2]=='D' && ss[2]=='C')) ) );
	return 0;
} 
