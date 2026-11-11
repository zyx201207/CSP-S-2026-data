#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> pai;
	long long t[m+1]={0};
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=0;k<pai.size();k++)
			{
				if(pai[k]==a[j])
				{
					for(int x=k;x<pai.size();x++) pai[x]=0;
					break;
				}
			}
			pai.push_back(a[j]);
		}
		for(int x=0;x<pai.size();x++) t[pai[x]]++;
		for(int x=0;x<pai.size();x++) pai[x]=0;
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<" ";
	return 0;
}
