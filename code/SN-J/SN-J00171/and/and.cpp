#include<bits/stdc++.h>
using namespace std;
int n,m,c=1,d=0;
int a[100005];
int e[10000005];
int h(int b)
{
	for (int i=0;i<=1;i++)
	{
		if(i==1)
		{
		c=a[b]>c;
		h(b++); 
		e[d]=c;
		}
	}
	if(b==m)
	{
		int i=1;
		for(int o=1;o<=m-1;o++)
			while(e[i]!=0)
			{
				if(e[i]<e[i+1])
				{
					e[i]=e[i+1];
				}
				i++;
				}
	return e[1] ;
	}
}
int main()
{	
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	void(1);
	cout<<e[1];
	return 0;
 } 
