#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sin signed
#define endl "\n"
string a,b;
int c,d;
sin main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>a>>d>>b;
	if(c==d)
	{
		cout<<"1";
		int tot=a[1]-'0';
		tot+=tot+(a[0]-'0')*10;
		int tott=b[1]-'0';
		tott+=tott+(b[0]-'0')*10;
		if(tot==tott)
		{
			cout<<"1";
			if(a[2]<='C'&&b[2]<='C'||a[2]>='D'&&b[2]>='D')
			{
				cout<<"1";
				if(abs(a[2]-b[2])==1)
				    cout<<"1"<<endl;
				else
				    cout<<"0"<<endl;
				return 0;
			}
			else
			{
				cout<<"00"<<endl;
				return 0;
			}
		}
		else
		{
			cout<<"000"<<endl;
			return 0;
		}
	}
	else if(c!=d)
	{
		cout<<"0000"<<endl;
		return 0;
	}
	return 0;
}