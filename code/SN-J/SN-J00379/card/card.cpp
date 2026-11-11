#include<bits/stdc++.h>
using namespace std;
int a[5005];
vector<int>zhuo;
int ans[5005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	for(int qwerty=1;qwerty<=n;qwerty++)
	{
		for(int i=qwerty;i<=n;i++)
		{
			for(int j=0;j<zhuo.size();j++)
			{
				if(zhuo[j]==k)
				{
					zhuo.clear();
					break;
				}
			}
			zhuo.push_back(a[i]);
		}
		for(int i=1;i<=zhuo.size();i++)
		{
			ans[zhuo[i]]++;
		}
	}
	for(int i=1;i<=k;i++)
	cout<<ans[i]<<" ";
	return 0;
}
