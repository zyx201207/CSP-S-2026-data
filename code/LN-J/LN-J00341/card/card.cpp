#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool b[105];
int sum[105];
int c;
int ans;
void work()
{
	for(int i=1;i<=n-ans;i++)
	{
		if(b[a[i]]==0)
		{
			b[a[i]]=1;
		}
		else
		{
			for(int j=1;j<=m;j++)
			{
				b[j]=0;
			}
			b[a[i]]=1;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}
	for(int j=1;j<=n;j++)
	{
    work();
    for(int i=1;i<=m;i++)
    {
		if(b[i]==1)   sum[i]=sum[i]+1;
		b[i]=0;
	}
	for(int i=1;i<=n;i++)
{
		  a[i]=a[i+1];
	}
	ans++;
}	
    for(int i=1;i<=m;i++)
    {
		cout<<sum[i]<<' ';
	}
    return 0;	
}
