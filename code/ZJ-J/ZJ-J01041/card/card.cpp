#include<bits/stdc++.h>
using namespace std;
int a[500005],v[300005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		cout<<n;
		return 0;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=k;i<=n;i++)
		{
			bool flag=1;
			for(int j=n;j>=i+1;j--)
			{
				if(a[i]==a[j])
				{
					i=j-1;
					flag=0;
					break;
				}
			}
			if(flag)
			{
				v[a[i]]++;
				continue;
			}
		}
	}
	for(int i=1;i<=m;i++) 
	{
		if(v[i]) cout<<v[i]<<" ";
	}
	return 0;
}