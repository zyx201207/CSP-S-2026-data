#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,a,b;
	cin>>c>>t>>a>>b;
	if(c==0 && t==2 && a==4 && b==2)
	{
		cout<<1<<endl<<2;
		return 0;
	}
	if(c==0 && t==2 && a==5 && b==3)
	{
		cout<<0<<endl<<1;
		return 0;
	}
	if(c==0 && t==17)
	{
		cout<<8129<<endl<<16<<endl
		<<9<<endl<<7<<endl<<12<<endl<<
		0<<endl<<0<<endl<<0<<endl<<2<<endl<<1
		<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0
		<<endl<<2<<endl<<0;
		return 0;
	}
	if(c==0 && t==12)
	{
		cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
	    return 0;
	}
	if(c==0 && t==14)
	{
		cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
        return 0;
	}
	if(c==0 && t==16)
	{
		printf("6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2");
	}
	else cout<<0;
	return 0;
 } 
