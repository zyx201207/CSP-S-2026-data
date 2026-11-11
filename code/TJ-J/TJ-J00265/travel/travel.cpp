#include<bits/stdc++.h>
using namespace std;
#define int long long
int c1,c2;
string s1,s2;
int ss1,ss2;
char a1,a2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	ss1=(s1[0]-'0')*10+(s1[1]-'0');
	ss2=(s2[0]-'0')*10+(s2[1]-'0');
	a1=s1[2],a2=s2[2];
//	cout<<ss1<<" "<<ss2<<"\n"<<a1<<" "<<a2<<"\n";
	if(c1==c2)
	{
		cout<<1;
		if(ss1==ss2)
		{
			cout<<1;
			if((a1<='C'&&a2<='C')||(a1>='D'&&a2>='D'))
			{
				cout<<1;
				int a=a1-a2;
				if(abs(a)==1)
				{
					cout<<1;
				}
				else cout<<0;
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
	else{
		cout<<"0000";
	}
	return 0;
}
