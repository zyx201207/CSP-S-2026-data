#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,zd=0;
    int s[50005]={0},d[50005]={0},js[30005]={0},l=0,w[30005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
	cin>>s[i];
	for(int c=1;c<i;c++)
	{
		if(d[c]==s[i]) l=1;
	}
	if(l==1)
	{
		for(int c=1;c<i-1;c++)
		{
			d[c]=0;
		}	
		d[i]=s[i];
	}
	else 
	{
	d[i]=s[i];
	w[i]=s[i];
	}
	}
	for(int i=1;i<=n;i++) if(d[i]!=0) js[d[i]]++;
	for(int q=2;q<=n;q++)
	{
	d[50005]={0};
	for(int i=q;i<=n;i++)
	{
	for(int c=1;c<i;c++)
	{
		if(d[c]==s[i]) l=1;
	}
	if(l==1)
	{
		for(int c=1;c<i-1;c++)
		{
			d[c]=0;
		}
		d[i]=s[i];
	}
	else d[i]=s[i];
	}
	for(int i=q;i<=n;i++) if(d[i]!=0) js[d[i]]++;
	}	
	for(int i=1;i<=m;i++)
	{
		cout<<js[w[i]];
	}
	return 0;
}