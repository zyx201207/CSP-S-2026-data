#include<bits/stdc++.h>
using namespace std;
int n,m;//n张牌就是n个回合 m种牌 
int a[500005];
int y1,y2;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
		if(a[i]==1)
		y1++;
		if(a[i]==2)
		y2++;
	}
	
	if(m==1)
	cout<<n;
	else if(m==2)
	{
		if(n==2)
		{
			if(a[1]==1)
			cout<<"1 2";
			else cout<<"2 1";
		}
		
		if(n==3)
		{
			if(y1>y2)
			{
				if(a[1]==1&&a[2]==1)
				cout<<"2 3";
				else 
				cout<<"3 1";
			}
			else 
			{
				if(a[1]==2&&a[2]==2)
				cout<<"3 2";
				else 
				cout<<"1 3";
			}
		}
		
		if(n==4)
		{
			
		} 
	}
	
	
	return 0;
}
