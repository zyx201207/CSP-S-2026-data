#include<bits/stdc++.h>
using namespace std;
char a[2],b[3],c[2],d[3];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	int aa=(a[0]-'0')*10+(a[1]-'0');
	int cc=(c[0]-'0')*10+(c[1]-'0');
	if(aa!=cc)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		int bb=(b[0]-'0')*10+(b[1]-'0');
		int dd=(d[0]-'0')*10+(d[1]-'0');
		if(bb!=dd)
		{
			cout<<"1000";
			return 0;
		}
		else
		{
			if((b[2]<='C' && d[2]>='C') || (b[2]<='D' && d[2]>='D'))
			{
				cout<<"1100";
				return 0;
			}
			else
			{
				if(abs(b[2]-d[2])!=1)
				{
					cout<<"1110";
					return 0;
				}
				else cout<<"1111";
			}
		}
	}
}