#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n;
	string a,b;
	cin>>a;
	cin>>m;
	cin>>b;
	bool flag1=0,flag2=0,flag3=0,flag4=0;
	if(n==m)
	{
		flag1=1;
		if(a[0]==b[0]&&a[1]==b[1])
		{
			flag2=1;
			if((a[2]<='C'&&b[2]<='C')||(a[2]>='D'&&b[2]>='D'))
			{
				flag3=1;
				if((a[2]=='A'&&b[2]=='B')||(a[2]=='B'&&b[2]=='A')||(a[2]=='B'&&b[2]=='C')||(a[2]=='C'&&b[2]=='B')||(a[2]=='D'&&b[2]=='E')||(a[2]=='E'&&b[2]=='D'))
				{
					flag4=1;
				}
			}
		}
	}
	//cout<<a<<" "<<b;
	if(flag1)cout<<'1';
	else cout<<'0';
	if(flag2)cout<<'1';
	else cout<<'0';
	if(flag3)cout<<'1';
	else cout<<'0';
	if(flag4)cout<<'1';
	else cout<<'0';
	cout<<"\n";
	return 0;
}
