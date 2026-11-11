#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,tot;
int a[500005];
struct node
{
	int val,num;
};
node b[500005];
int sumn[500005];
int sumnv[500005];
int calc(int l,int r)
{
	return b[r].val*(sumn[r]-sumn[l-1])-(sumnv[r]-sumnv[l-1]);
}
bool check(int l,int r)
{
	/*
	 \sum_{i=l}^{r} num[i](val[r]-val[i])
	=\sum_{i=l}^{r} (num[i]val[r]-num[i]val[i])
	=val[r]\sum_{i=l}^{r}num[i]-\sum_{i=l}^{r}num[i]val[i]
	*/
	return (b[r].val*(sumn[r]-sumn[l-1])-(sumnv[r]-sumnv[l-1])) <= m;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	a[n+1] = 1e18;
	sort(a+1,a+n+1);
	int cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		cnt++;
		if(a[i] != a[i+1])
		{
			b[++tot] = {a[i],cnt};
			cnt = 0;
		}
	}
	for(int i = 1;i <= tot;i++)
	{
		sumn[i] = sumn[i-1]+b[i].num;
		sumnv[i] = sumnv[i-1]+b[i].num*b[i].val;
	}
	int ans = 0;
	for(int i = 1;i <= tot;i++)
	{
		int lt = 1,rt = i;
		while(lt < rt)
		{
			int mid = (lt+rt)/2;
			if(calc(mid,i) <= m)
			{
				rt = mid;
			}
			else
			{
				lt = mid+1;
			}
		}
		int now = sumn[i]-sumn[rt-1];
		if(rt > 1)
		{
			now += min((m-calc(rt,i))/(b[i].val-b[rt-1].val),b[rt-1].num);
		}
		ans = max(ans,now);
	}
	cout << ans << "\n";
	return 0;
}

