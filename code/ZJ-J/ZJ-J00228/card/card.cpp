#include<bits/stdc++.h>
using namespace std;
const int N=3e5+100;
int n,m,ans[2*N],a[2*N],q[2*N],c[N];
int r[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		r[a[i]]=ans[i]=i;
		q[i]=ans[i]-ans[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		ans[i]=ans[i-1]+q[i];
		q[i+1]-=ans[i];
		q[r[a[i]]+1]+=ans[i];
	}
	for(int i=1;i<=n;i++)
		c[a[i]]+=ans[i];
	for(int i=1;i<m;i++)
		cout<<c[i]<<" ";
	cout<<c[m];
	return 0;
}