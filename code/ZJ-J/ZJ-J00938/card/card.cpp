#include<bits/stdc++.h>
using namespace std;
int n,m,a[500050],b[500050],c[500050],cnt[300030],t;
vector<int> T[300030];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		b[i]=0;
		c[i]=n+1;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
//		cin>>a[i];
		if(T[a[i]].size()!=0)
		{
			b[i]=T[a[i]][T[a[i]].size()-1];
			c[T[a[i]][T[a[i]].size()-1]]=i;
		}
		T[a[i]].push_back(i);
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;
//	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(c[j]<=n)
			{
				j=c[j]-1;
//				cout<<"1 "<<i<<" "<<j<<" "<<a[i]<<endl;
			}
			else
			{
				cnt[a[j]]++;
//				cout<<"2 "<<i<<" "<<j<<" "<<a[j]<<endl;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	cout<<endl;
}