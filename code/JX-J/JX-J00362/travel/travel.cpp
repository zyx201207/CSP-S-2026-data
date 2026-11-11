#include <bits/stdc++.h>
using namecpace std;

string c1,s1,c2,s2;
char a[2];
bool cl,sl;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	
	cin>>c1>>s1>>c2>>s2;
	a[0]=c2[2];
	a[1]=s2[2];
	sort(a,a+1);
	if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C') cl=0;
	else cl=1;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') sl=0;
	else sl=1;
	if(c2[2]=='A') 
	
	if(c1==s1)
	{
		cout<<1;
		if(c2[0]==s2[0]&&c2[1]==s2[1])
		{
			cout<<1;
			if(cl==sl)
			{
				cout<<1;
				if(a[0]=='A'||a[0]=='B'||a[0]=='D') cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	
	
	return 0;
}
