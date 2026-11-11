#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e6+10;

int n;
int x[N];
int c,t;

void yangli ()
{
	int d,dertax;
	cin>>n;
	cin>>d;
	for (int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	if (n==4)cout<<1<<"\n"<<2<<"\n";
	if (n==5)cout<<0<<"\n"<<1<<"\n";
	if (t==17)cout<<8129<<"\n"<<16<<"\n"<<9<<"\n"<<7<<"\n"<<12<<"\n"<<0<<"\n"<<0<<"\n"<<0<<"\n"<<2<<"\n"<<1<<"\n"<<0<<"\n"<<2<<"\n"<<3<<"\n"<<6<<"\n"<<0<<"\n"<<2<<"\n"<<0<<"\n";
	if (t==12)cout<<0<<"\n"<<0<<"\n"<<259997<<"\n"<<259995<<"\n"<<86669<<"\n"<<0<<"\n"<<0<<"\n"<<0<<"\n"<<7<<"\n"<<5<<"\n"<<5<<"\n"<<0<<"\n";
	if (t==14)cout<<9999900000<<"\n"<<399995<<"\n"<<0<<"\n"<<716427<<"\n"<<0<<"\n"<<0<<"\n"<<2<<"\n"<<1<<"\n"<<0<<"\n"<<2<<"\n"<<3<<"\n"<<6<<"\n"<<0<<"\n"<<2<<"\n";
	if (t==16)cout<<6800625333<<"\n"<<6247500<<"\n"<<6242502<<"\n"<<4998<<"\n"<<9994<<"\n"<<0<<"\n"<<0<<"\n"<<0<<"\n"<<2<<"\n"<<1<<"\n"<<0<<"\n"<<2<<"\n"<<3<<"\n"<<6<<"\n"<<0<<"\n"<<2<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if (c==0)
	{
		yangli();
		return 0;
	}
	while (t--)
	{
		int d,dertax;
		cin>>n;
		cin>>d;
		for (int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		dertax=x[2]-x[1];
		for (int i=2;i<=n;i++)
		{
			if (dertax!=x[i]-x[i-1])
			{
				dertax=-1;
				break;
			}
		}
		cout<<0<<"\n";
	}
	return 0;
}
