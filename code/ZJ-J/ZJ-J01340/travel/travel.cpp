#include<bits/stdc++.h>
using namespace std;
char a[20];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=10;i++)
	{
		cin>>a[i];
	}
	if(a[1]!=a[6]||a[2]!=a[7])
	{
		cout<<"0000"<<'\n';
	}
	else
	{
		cout<<"1";
		if(a[3]!=a[8]||a[4]!=a[9])
		{
			cout<<"000"<<'\n';
		}
		else
		{
			cout<<"1";
			if((int(a[5])<68&&int(a[10])<68)||(int(a[5])>=68&&int(a[10])>=68))
			{
				cout<<"1";
				if((int(a[5])+1==int(a[10]))||(int(a[5])-1==int(a[10])))
				{
					cout<<"1"<<'\n';
				}
				else cout<<"0"<<'\n';
			}
			else
			{
				cout<<"00"<<'\n';
			}
		}
	}
	return 0;
}