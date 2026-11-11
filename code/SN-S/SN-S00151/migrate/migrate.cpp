#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2000010;
ll subtask,T,n,m,ans,a[N],lsp[N],rsp[N],prf[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>subtask>>T;
	if (subtask<=10)
	{
		while(T--)
		{
			cin>>n>>m;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
				lsp[i]=rsp[i]=prf[i]=0;
			}
			ans=0;
			for(int i=1;i<=n;i++)
			{
				lsp[i]=lower_bound(a+1,a+n+1,a[i]-m)-a;
				rsp[i]=min(upper_bound(a+1,a+n+1,a[i]+m)-a-1,n);
			}
			for(int i=1;i<=n;i++)
			{
				if (rsp[i]==n)
					break;
				prf[i]=0;
				for(int j=i+1;j<=rsp[i];j++)
					prf[j]=prf[j-1]+1;
				for(int lt=rsp[i],rt=rsp[lt];lt<n&&lt!=rt;lt=rt,rt=rsp[lt])
				{
					for(int j=lt+1;j<=rt;j++)
					{
						ll k=prf[lt]-prf[lsp[j]-1];
						if (k==2)
							ans++;
						prf[j]=prf[j-1]+k;
					}
					if (prf[rt]-prf[rt-1]>2)
						break;
				}
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	if (subtask<=12)
	{
		while(T--)
		{
			cin>>n>>m;
			for(int i=1;i<=n;i++)
				cin>>a[i];
			if (m>=(a[n]-a[n-1])*3||m<(a[n]-a[n-1])*2)
			{
				cout<<"0\n";
				continue;
			}
			cout<<max(0ll,n-3)<<"\n";
		}
		return 0;
	}
}
