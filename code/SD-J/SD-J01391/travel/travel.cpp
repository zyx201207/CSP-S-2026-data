#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		cout<<1;
	else 
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	int n,m;
	if(s1[0]=='0')
		n=int(s1[1]);
	else n=int(s1[0]+s1[1]);
	if(s2[0]=='0')
		m=int(s2[1]);
	else m=int(s2[0]+s2[1]);
	if(n==m) cout<<1;
	else 
	{
		cout<<0<<0<<0;
		return 0;
	}
	if((s1[2]>='A' && s1[2]<='C' && s2[2]>='D' && s2[2]<='F') || (s2[2]>='A' && s2[2]<='C' && s1[2]>='D' && s1[2]<='F'))
	{
		cout<<0<<0;
		return 0;
	}
	else cout<<1;
	if(abs(int(s1[2])-int(s2[2]))==1) cout<<1;
	else cout<<0;
	return 0;
}
