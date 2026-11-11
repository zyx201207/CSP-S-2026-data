#include<bits/stdc++.h>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n1,n2,ans[6]={};
	char a1,a2,a3,b1,b2,b3;
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n1>>a1>>a2>>a3;
	cin>>n2>>b1>>b2>>b3;
	if(n1==n2)
	{
		ans[1]=1;
		if(a1==b1 && a2==b2)
		{
			ans[2]=1;
			if(a3<'D' && b3<'D' || a3>'C' && b3>'C')
			{
				ans[3]=1;
				if(a3+1==b3 || b3+1==a3)
				{
					ans[4]=1;
				}
			}
		}
	}
	for(int i=1;i<=4;i++)
	{
		cout<<ans[i];
	}
	return 0;
}
