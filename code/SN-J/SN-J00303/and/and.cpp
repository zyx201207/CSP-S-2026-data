#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int m[a+1];
	for(int i=0;i<a;i++)
	{
		cin>>m[i];
	}
	int k[a*(a-1)/2],t=0;
	if(b==2)
	{
		for(int i=0;i<a;i++)
		{	
			for(int j=0;j<a;j++)
			{
				k[t]=m[i]&m[j];
				t++;
			}
		}
		sort(k+1,k+(a*(a-1)/2)+1);
		cout<<k[a*(a-1)/2-1];
	}
	if(b==1)
	{
		int h=0;
		for(int i=0;i<a;i++)
		{
			if(m[i]>h)
			{
				h=m[i];
			}
		}
		cout<<h;
	}
	if(b==a)
	{
		int y=m[0]&m[1];
		for(int i=2;i<a;i++)
		{
			y=y&m[i];
		}
		cout<<y;
	}
	
}
