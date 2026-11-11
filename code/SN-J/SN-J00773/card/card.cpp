//SN-J00773 林靖轩 西安辅轮中学
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m;
int a[N],ans[M],cnt[M],id[M];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	for(int i=n;i>=1;i--)
	{
		if(cnt[a[i]]!=0)
		{
			cnt[a[i]]++;
//			cout<<i<<"    "<<id[a[i]]<<"\n";
			int cc1=i,cc2=id[a[i]];
			for(int j=cc1;j<cc2;j++)
				cnt[a[j]]--,a[j]=0;
				
		}
		else
		{
			cnt[a[i]]++;
			id[a[i]]=i;
		}
		for(int i=1;i<=m;i++)
			if(cnt[i]!=0)ans[i]++;
//		for(int i=1;i<=n;i++)
//			cout<<a[i]<<" ";
//		cout<<"\n";
//		for(int i=1;i<=m;i++)
//			cout<<ans[i]<<" ";
//		cout<<"\n";
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
/*
4 3
1 2 1 3
*/
