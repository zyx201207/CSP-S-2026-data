#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int a[N],ans[N];
	bool sA=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>1)
		{
			if(a[i]<a[i-1])
				sA=false;
		}
	}
	if(sA)
	{
		int cha[N];
		memset(cha,0,sizeof(cha));
		for(int i=1;i<=n;i++)
			cha[a[i]]++;
		cout<<cha[1];
		for(int i=2;i<=m;i++)
		{
			cout<<' ';
			cha[i]+=cha[i-1];
			cout<<cha[i];
		}
		cout<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		bool t[N];
		int l[N];
		memset(t,false,sizeof(t));
		for(int j=i;j<=n;j++)
		{
			if(t[a[j]])
			{
				for(int k=l[a[j]];k<=j-1;k++)
					t[a[k]]=false,l[a[j]]=0;
			}
			t[a[j]]=true;
			l[a[j]]=j;
		}
		for(int j=1;j<=m;j++)
		{
			if(t[j])
				ans[j]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(i>1)
			cout<<' ';
		cout<<ans[i];	
	}
	cout<<endl;
	return 0;
}
