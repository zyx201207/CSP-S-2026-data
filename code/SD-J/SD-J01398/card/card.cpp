#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[300005];
vector<int> v,s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		v.push_back(k);
	}
	if(n<5)
	{
		for(int i=0;i<v.size();i++)
		{
			bool f=0,f1=0;
			for(int j=0;j<v.size();j++)
			{
				if(v[j]==1&&!f)a[1]++,f=0;
				if(v[j]==2&&!f1)a[2]++,f1=0;
			}
		}
		cout<<a[1]<<" "<<a[2];
	}
	else
	{
		k=1;
		v.push_back(INT_MAX);
		for(int i=0;i<=n;i++)
		{
			if(v[i]!=k)k++,a[k-1]=i;
		}
		for(int i=1;i<=m;i++)cout<<a[i]<<endl;
	}
}
