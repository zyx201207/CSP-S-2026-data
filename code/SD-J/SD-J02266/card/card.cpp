#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[500010],b[500010],ans[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		memset(b,0,sizeof b);
		ll t=0;
		for (int j=i;j<=n;j++)
		{
			if(b[a[j]])
			{
				for (int k=1;k<=m;k++)
				{
					if (b[k]>b[a[j]]) b[k] = 0;
				}
				t = b[a[j]];
			}
			else b[a[j]] = ++t;
		}
		for (int j=1;j<=m;j++) if (b[j]) ans[j]++;
	}
	for (int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
} 
