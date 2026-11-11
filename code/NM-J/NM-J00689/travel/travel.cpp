#include<bits/stdc++.h>
using namespace std;
//#define int long long
int n,m,c1,c2;
char s1,s2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&c1);
	scanf("%c",&s1);
	scanf("%d%d",&m,&c2);
	scanf("%c",&s2);
	if(n==m)
	{
		cout<<1;
		if(c1==c2)
		{
			cout<<1;
			if((s1=='C'&&s2=='D')||(s1=='D'&&s2=='C'))
			{
				cout<<"00";
				return 0;
			}
			else
			{
				if((s1>='A'&&s1<='C'&&s2>='A'&&s2<='C')||(s1>='D'&&s1<='F'&&s2>='D'&&s2<='F'))
				{
					cout<<1;
					if((s1=='D'&&s2=='F')||(s1=='F'&&s2=='D'))
					{
						cout<<1;
						return 0;
					}
					else if((s1+1==s2)||(s2+1==s1))
					{
						cout<<1;
						return 0;
					}
					else
					{
						cout<<0;
						return 0;
					}
				}
			}
		}
		else
		{
			cout<<"000";
			return 0;
		}
	}
	else
	{
		cout<<"0000";
		return 0;
	}
//	cout<<n<<" "<<c1<<" "<<s1<<" "<<m<<" "<<c2<<" "<<s2;
	return 0;
}
