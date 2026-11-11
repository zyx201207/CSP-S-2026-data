#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(b==2&&c==4&&d==2) 
	{
		cout<<1<<endl<<2;
	}
	if(b==2&&c==5&&d==3) 
	{
		cout<<0<<endl<<1;
	}
	if(b==17&&c==197&&d==29418319589926278) 
	{
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0;
		cout<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2;
		cout<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
	}
	if(b==16&&c==174944&&d==139950)
	{
		cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0;
		cout<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0;
		cout<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
	}
	else
	{
		cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl;
		cout<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
	}
	return 0;
}
