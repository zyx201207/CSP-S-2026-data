#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    ans[a[n]]=n;
    int x=n-1;
    for(int i=n-1;i>=1;i--)
    {
		if(ans[a[i]]==0)
		{
			ans[a[i]]=x;
			x--;
		}
	}
	for(int i=1;i<=m;i++)cout << ans[i] << " ";
    return 0;
}
