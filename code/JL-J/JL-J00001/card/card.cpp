#include<bits/stdc++.h>
using namespace std;
#define N 500005
int a[N],t[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		vector<int> v;
		int l=-1;
		for(int j=i;j<=n;j++)
		{
			v.push_back(a[j]);
			l++;
			for(int k=0;k<l;k++)
			{
				if(v[k]==v[l])
				{
					v.erase(v.begin()+k,v.begin()+l);
					l-=(l-k);
				}
			}
		}
		for(int j=0;j<=l;j++)
		{
			t[v[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<t[i]<<" ";
	cout<<'\n';
	return 0;
}
