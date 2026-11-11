#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],t[300005],lst[300005],pos,ans[300005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(n<=500)//24pts
	{
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=m;i++)
			lst[i]=-1;//a[i]出现的位置下标i 
			pos=0;
			for(int i=k;i<=n;i++)
			{
				if(lst[a[i]]==-1)
				{
					ans[++pos]=a[i];
					lst[a[i]]=pos;
				}
				else
				{
					for(int j=lst[a[i]]+1;j<=pos;j++)
					lst[ans[j]]=-1;
					pos=lst[a[i]];
				}
	//			for(int j=1;j<=pos;j++)
	//			cout<<ans[j]<<" ";
	//			cout<<endl;
			}
			for(int i=1;i<=pos;i++)
			t[ans[i]]++;
		}
		for(int i=1;i<=m;i++)
		cout<<t[i]<<" ";
	}
	else//[16pts,76pts]???
	{
		a[n+1]=11431143;//114399
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[i+1])
			t[a[i]]+=i;
		}
		for(int i=1;i<=m;i++)
		cout<<t[i]<<" ";
	}
	return 0;
}
