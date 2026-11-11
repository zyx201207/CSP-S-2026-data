#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m;
long long a[N],ans[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans[a[i]]++;
	}
	ans[a[n]]=n;
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
