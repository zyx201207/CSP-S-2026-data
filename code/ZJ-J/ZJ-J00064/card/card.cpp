#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,sum[N];
int a[N],lst[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;)
		{
			if(lst[a[j]]!=j){
				j=lst[a[j]];
				continue;
			}
			else 
			{
				sum[a[j]]++;
			}
			j++;
		}
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
	return 0;
}
