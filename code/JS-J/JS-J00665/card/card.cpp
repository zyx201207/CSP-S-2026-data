#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100,M=3e5+100;
int a[N],last[M],ans[M],t[M],nxt[N];
int n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		nxt[i]=i+1;
	}
	for(int i=n;i>=1;i--)
	{
		if(last[a[i]]!=0)
			nxt[i]=nxt[last[a[i]]];
		int j=i;
		while(j<=n){
			ans[a[j]]++;
			j=nxt[j];
		}
		last[a[i]]=i;
	}
	for(int j=1;j<=m;j++)
	{
		cout<<ans[j]<<" ";
	}
	return 0;
}
