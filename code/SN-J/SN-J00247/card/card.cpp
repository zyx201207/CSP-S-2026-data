#include<bits/stdc++.h>
using namespace std;
int arr[200005];
int used[100005],have[100005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	stack<int>zhan;
	for(int i=1;i<=n;i++)
	{
		while(zhan.size())zhan.pop();
		for(int i=1;i<=m;i++)used[i]=0;
		for(int j=i;j<=n;j++)
		{
			if(used[arr[j]]==0)
			{
				
				zhan.push(arr[j]);
				used[arr[j]]++;
			}
			else if(used[arr[i]]==1)
			{
				while(zhan.top()!=arr[j])
				{
					used[zhan.top()]--;
					zhan.pop();
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(used[j]!=0)have[j]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<have[i]<<" ";
	}
}
