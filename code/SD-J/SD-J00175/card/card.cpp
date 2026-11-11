#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int arr[n+1],arr1[m+1]={0};
	for (int i=1;i<=n;i++) cin>>arr[i];
	for (int i=1;i<=n;i++)
	{
		vector<int> v;
		for (int j=i;j<=n;j++)
		{
			int a=0,b=0;
			for (int k=0;k<v.size();k++)
			{
				if (v[k]==arr[j])
				{
					a=1;
					b=k;
					break;
				}
			}
			if (a==1) for (int k=0;k<v.size()-b-1;k++) v.pop_back();
			else v.push_back(arr[j]);
		}
		for (int j=0;j<v.size();j++) arr1[v[j]]++;
	}
	for (int i=1;i<=m;i++) cout<<arr1[i]<<" ";
	return 0;
}
