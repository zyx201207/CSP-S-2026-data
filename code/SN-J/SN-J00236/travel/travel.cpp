#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen  (travel.in,"r","stdin");
	freopen  (travel.out,"w","stdout");
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	mj ,mj,mj,mj; 
	int a[20];
	for(int i=2;i<=17;i++)
	{
		cin>>a[i];
		if(i==a)
		{
			cout<<"1"<<" ";
			if(i==b)
			{
				cout<<"1"<<" ";
				if(i==c)
				{
					cout<<"1"<<" ";
					if(i==d)
					{
						cout<<"1"<<" ";
					}
					else
					{
						cout<<"0"<<" ";
					}
				}
				else
				{
					cout<<"1"<<" ";
				}
			}
			else
			{
				cout<<"0"<<" ";
			}
		}
		else
		{
			cout<<"0"<<" ";
		}
	}
}

