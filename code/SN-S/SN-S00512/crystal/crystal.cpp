#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	int min=10086;
	int qwe=0;
    int a[5001];
    int b[5001];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	
	while(m>0)
{
	for(int j=1;j<=n-1;j++)
	{
		b[j]=a[j+1]-a[j];
	}
	for(int h=1;h<=n-1;h++)
	{
		if(b[h]<min&&b[h]!=0)
		{
			min=b[h];
		}
	}
	if(min<=m)
	{
	for(int g=1;g<=n-1;g++)
	{
		if(b[g]==min)
		{
			a[g]+=min;
			m -= min;
			break;
		}
	}
    }
    else
    break;
}
    for(int d=1;d<=n;d++)
    {
    	if(a[d]==a[d+1])
    	{
    		qwe++;
		}
	} 
	if(qwe!=0)
	{
		qwe++;
	}
	cout<<qwe;
	
	return 0;
}
