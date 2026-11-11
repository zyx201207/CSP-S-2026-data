#include<bits/stdc++.h>
using namespace std;
int m,n,l=1;
long long sum[50050],px[50050];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>px[i];
	}
		
	
	if(m==1)
	{
		cout<<n;
		return 0;
	}
	
	for(int i=1;i<n;i++)
	{
		if(px[i]==px[i+1])
		{
			sum[l]++;
		}
		else
		{
			sum[l]++;
			l++;
		}
	}
	sum[l]++;
	for(int i=1;i<=l;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0; 
}
