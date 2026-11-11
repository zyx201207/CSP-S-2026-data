#include<bits/stdc++.h>
using namespace std;
long long a,b,c[500001],c2[500001],c3[500001],c1[300001][3],w,p; 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++)
		cin>>c[i];
	for(int i=1;i<=a;i++)
	{
		w=0;
		memset(c1,0,sizeof(c1));
		p=0;
		for(int j=i;j<=a;j++)
		{
			if(c1[c[j]][1]==0)
			{
				w++;
				c2[w]=c[j];
				c1[c[j]][1]=1;
				c1[c[j]][2]=w;
			}
			else
			{
				for(int k=c1[c[j]][2]+1;k<=w;k++)
					c1[c2[k]][1]=0;
				w=c1[c[j]][2];
				p=1;
			}
		}
		if(p==0)
			break;
		for(int j=1;j<=w;j++)
			c3[c2[j]]++;
	 } 
	for(int i=1;i<=w;i++)
		for(int j=i;j<=w;j++)
			c3[c2[j]]++;
	for(int i=1;i<=b;i++)
		cout<<c3[i]<<" ";
	return 0;
} //AC
