#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
signed main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	
	int ha1=s1[0]*10+s1[1],ha2=s2[0]*10+s2[1];
	if(ha1!=ha2)
	{
		cout<<"000";
		return 0;
	}
	else cout<<1;
	
	
	if((s1[2]<='C' && s2[2]<='C') || (s1[2]>'C' && s2[2]>'C'))
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	
	if(s1[2]-1==s2[2] || s1[2]+1==s2[2]) cout<<1;
	else cout<<0;
	
	return 0;
}