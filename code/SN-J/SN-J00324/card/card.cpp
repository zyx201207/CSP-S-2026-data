#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int lst[N],a[N];
int ans[N],kd[N];
int n,m;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
//	bool flag=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	for(int i=1;i<=n;i++) lst[a[i]]=i;
	int b=1;
	for(int i=1;i<=n;i++)
	{
		if(lst[a[i]]==i)
		{
			ans[a[i]]+=(b++);
			continue; 
		}
		for(int j=i;j<=n;j++)
		{
			j=lst[a[j]];
			ans[a[j]]+=b;
		}
		b=1;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;	
}















//fjy I love you!
