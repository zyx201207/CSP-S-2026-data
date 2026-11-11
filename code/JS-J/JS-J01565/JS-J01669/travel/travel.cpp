#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	bool f1=0,f2=0,f3=0;
	if(c1==c2)
	{
		cout<<1;
		if(s1[0]==s2[0] and s1[1]==s2[1])
		{
			f1=1;
			if((s1[2]>='D' and s2[2]>='D') or (s1[2]<'D' and s2[2]<'D'))
			{
				f2=1;
				if(abs(s1[2]-s2[2])==1) f3=1;
			}
		}
		
	}
	else cout<<0;
	if(f1) cout<<1;
	else cout<<0;
	if(f2) cout<<1;
	else cout<<0;
	if(f3) cout<<1;
	else cout<<0;
	return 0;
}
