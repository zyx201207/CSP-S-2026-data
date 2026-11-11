#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,x,b,y,t1,t2;
	int i,l1,l2;
	cin>>a>>x>>b>>y;
	if(a!=b)
	{
		cout<<'0'<<'0'<<'0'<<'0'; 
	}
	else
	{
		cout<<'1';
		l1=x.size();
		l2=y.size();
		t1=x[0]+x[l1-2];
		t2=y[0]+y[l2-2];
		if(t1!=t2)
		{
			cout<<'0'<<'0'<<'0'; 
		}
		else
		{
			cout<<'1';
			if((x[l1-1]=='D'&&y[l2-1]=='E')||((x[l1-1]=='A'||x[l1-1]=='B'||x[l1-1]=='C')&&(y[l2-1]=='A'||y[l2-1]=='B'||y[l2-1]=='C')))
			{
				cout<<'1';
				if(x[l1-1]==(y[l2-1]+1)||y[l2-1]==(x[l1-1]+1))
				{
					if(x[l1-1]!='D'&&y[l2-1]!='D')
					{
						cout<<'1';
					}
					else
					{
						cout<<'0';
					}
				}
				else
				{
					cout<<'0';
				}
			}
			else
			{
				cout<<'0'<<'0'; 
			}
		}
	}
	return 0;
} 
