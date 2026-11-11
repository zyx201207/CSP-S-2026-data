#include<bits/stdc++.h>
using namespace std;
int a[200005],flag[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=n;i>=1;i--)
	{
		if(flag[a[i]]==0)
		{
			flag[a[i]]=i;
		}
	}
	for(i=1;i<=m;i++)
	{
		cout<<flag[i]<<" ";
	}
	return 0;
} 
