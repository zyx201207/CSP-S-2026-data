#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int a[n+1],b[n+1]={0};
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;++i)
	{
		int ii=i;
		for(int j=i;j<=n;j++)
		{
			for(int k=ii;k<j;k++)
			{
				if(a[k]==a[j])
				{
					ii=j;
					break;
				}
			}
		}
		while(ii<=n)
		{
			b[a[ii]]++;
			ii++;
		}
	}
	b[a[n]]=n;
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
