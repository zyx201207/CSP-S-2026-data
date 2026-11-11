#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,a,b,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	a+=s1[0]+s1[1],b+=s2[0]+s2[1];
	if(c1!=c2)cout<<"0000";
	else 
	{
		cout<<1;
		if(a==b)
		{
			cout<<1;
			if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'))
			{
				cout<<1;
				int h=s1[2],h2=s2[2];
				if(h-1==h2||h+1==h2)cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
}
