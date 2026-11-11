//zbh   °¿ÏèÖĞÑ§    SN-J00659 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie();
	string c1,c2,s_1,s2;
	cin>>c1>>s_1>>c2>>s2;
	char p1=s_1[2],p2=s2[2];
	string z1;
	string z2;
	for(int i=0;i<=1;i++)
	{
		z1+=s_1[i];
		z2+=s2[i];
	}
	if(c1==c2)
	{
		cout<<1;
		if(z1==z2)
		{
			cout<<1;
			if((p1=='F' and p2=='D') or (p1=='D' and p2=='F'))
			{
				cout<<1<<1;
			}
			else if(p1!='F' and p1!='D' and p2!='F' and p2!='D')
			{
				cout<<1;
				if(p1+1==p2 or p2+1==p1) cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
