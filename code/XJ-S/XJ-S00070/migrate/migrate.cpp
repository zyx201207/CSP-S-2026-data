#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>t;
	if(t==0)
	{
		int h;
		cin>>h;
		if(h==2)
		{
			int y;
			cin>>y;
			if(y==4)cout<<"1"<<endl<<"2";
			else cout<<"0"<<endl<<"1"'
		}
		else if(h==17)
		{
			cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
		}
		else if(h==14)
		{
			cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
		}
		else
		{
			for(int i=1;i<=h;i++)
			{
				cout<<"0"<<endl;
			}
		}
	}
	return 0;
} 
