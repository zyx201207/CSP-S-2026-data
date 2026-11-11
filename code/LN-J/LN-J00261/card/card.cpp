#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],cnt[M],b[M];
void solve()
{
	int n,m,pos=0;
	bool flag=true;
	cin>>n>>m;
	if(n==m) flag=true;
	for(int i=0;i<n;i++) 
		cin>>a[i];	
	while(m--&&flag==false)
	{
		for(int i=0;i<n;i++) 
		{
			if(i)
			{
				for(int j=i-1;j>=0;j--)
				{
					if(a[j]==a[i]&&j>pos) pos=j;
				}
			}	
		}	
		for(int i=pos+1;i<n;i++)
		{
			if(cnt[a[i]]==0) cnt[a[i]]++;
		}	
	}
	if(flag==false) 
		for(int i=0;i<m;i++) cout<<cnt[i]<<" ";	
	else 
		for(int i=0;i<=m;i++) cout<<n-i<<" ";
}	
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	solve();
	return 0;
}
