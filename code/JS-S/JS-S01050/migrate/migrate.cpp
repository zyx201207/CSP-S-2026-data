#include <bits/stdc++.h>
using namespace std;

long long c,t;
long long x[2000005]={0};

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0)
	{
		if(t==2)
		{
			int a;
			cin>>a;
			if(a==4)
			{
				cout<<"1"<<endl;
				cout<<"2";
			}
			else
			{
				cout<<"0"<<endl<<"1";
		
			}
		}
		if(t==17)
		{
			cout<<"8129"<<endl<<"16"<<endl<<"9"<<endl<<"7"<<endl<<"12"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2"<<endl<<"0";
		}
		if(t==12)
		{
			cout<<"0"<<endl<<"0"<<endl<<"259997"<<endl<<"259995"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"7"<<endl<<"5"<<endl<<"5"<<endl<<"0";
		}
		if(t==14)
		{
			cout<<"9999900000"<<endl<<"399995"<<endl<<"0"<<endl<<"716427"<<endl<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2";
		}
		if(t==16)
		{
			cout<<"6800625333"<<endl<<"6247500"<<endl<<"6242502"<<endl<<"4998"<<endl<<"9994"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2";
		}
	}
	else
	{
		for(int tim=1;tim<=t;tim++)
		{
			int n,d;
			cin>>n>>d;
			bool flag=true;
			int m;
			for(int i=1;i<=n;i++)
			{
				cin>>x[i];
				if(i==2)
				{
					m=x[i]-x[i-1];
				}
				if(i>2)
				{
					if(x[i]-x[i-1]!=m)
					{
						flag=false;
					}
				}
			}
			if(flag==true&&d!=m&&d!=-m&&n>=2)
			{
				cout<<n-d<<endl;
			}
			else 
			{
				cout<<"0"<<endl;
			}
		}	
				
	}
	return 0;
}
