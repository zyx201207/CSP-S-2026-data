#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m,a[N],ans[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int cnt[M]={};
		for(int j=i;j<=n;j++)
		{
			cnt[a[j]]++;
			if(cnt[a[j]]==2)
			{
				bool flag=false;
				for(int k=j;;k--)
				{
					cnt[a[k]]--;
					if(a[k]==a[j]&&flag) break;
					flag=true;
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(cnt[i]>0) ans[i]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
