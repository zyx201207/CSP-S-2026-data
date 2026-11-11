#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string m,n,a,b;
	cin>>m>>a>>n>>b;
	string kx,ky;
	char p=a[0];
	char pp=a[1];
	kx+=p;
	kx+=pp;
	p=b[0];
	pp=b[1];
	ky+=p;
	ky+=pp;
	if(m!=n)
	{
		cout<<"0000";
	}
	else
	{
		cout<<'1';
		if(kx==ky)
		{
			cout<<'1';
			char l1=a[2];
			char l2=b[2];
			if(l1=='A'||l1=='B'||l1=='C')
			{
				if(l2=='A'||l2=='B'||l2=='C')
				{
					cout<<'1';
					if(l1=='A'||l1=='B')
					{
						if(l2=='A'||l2=='B')
						{
							cout<<'1';
						}
						else if(l1=='B'&&l2=='C')
						{
							cout<<'1';
						}
						else
						{
							cout<<'0';
						}
					}
					if(l1=='C'&&l2=='B')
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
					cout<<"00";
				}
			}
			else if(l1=='D'||l1=='F')
			{
				if(l2=='D'||l2=='F')
				{
					cout<<"11";
				}
				else
				{
					cout<<'0';
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	return 0;
}
