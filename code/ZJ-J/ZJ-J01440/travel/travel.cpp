#include<bits/stdc++.h>
using namespace std;
int x,y,x2,y2,f,f2;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	x=(a[0]-'0')*10+(a[1]-'0');
	y=(b[0]-'0')*10+(b[1]-'0');
	x2=(c[0]-'0')*10+(c[1]-'0');
	y2=(d[0]-'0')*10+(d[1]-'0');
	if(b[2]>='A'&&b[2]<='C')f=1;
	if(d[2]>='A'&&d[2]<='C')f2=1;
	if(x==x2)
	{
		cout<<1;
		if(y==y2)
		{
			cout<<1;
			if(f==f2)
			{
				cout<<1;
				if(f==0)cout<<1;
				else
				{
					if((b[2]=='C'&&d[2]=='A')||(b[2]=='A'&&d[2]=='C'))cout<<0;
					else cout<<1;
				}
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}