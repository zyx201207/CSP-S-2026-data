#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],visi[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1) cout<<n;
	else if(m==2)
	{
		cout<<n/2<<" "<<(n+1)/2;
	}
	else 
	{
		for(int j=1;j<=n;j++)
		{
			int num=0;
			for(int i=j;i<=n;i++)
			{
				if(a[i]==a[i+1]) 
				{
					a[i+1]=0;
					num++;
				}
			}
			sort(a+1,a+1+n-num);
			for(int i=j;i<=n;i++)
			{
				visi[a[i]]++;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<a[i]<<" ";
		}
	}
 	return 0;
} 
