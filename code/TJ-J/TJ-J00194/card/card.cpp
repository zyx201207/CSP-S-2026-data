#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,a[500005],ans[300005];
struct card
{
	ll l,r,val;
}cards[500005];
int main()
{
	freopen("card.in",'r',"stdin");
	freopen("card.out",'w',"stdout");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (ll i=1;i<=n;i++) cin>>a[i];
	for (ll i=1;i<=n;i++)
	{
		bool flag=true;
		memset(cards,0,sizeof cards);
		for (ll j=i;j<=n;j++)
		{
			if (j!=1) cards[a[j]].l=a[j-1];
			else cards[a[j]].l=0;
			cards[a[j]].val=a[j];
			if (j!=n) cards[a[j]].r=a[j+1];
			else cards[a[j]].r=0;
		}
		for (ll j=i;j<=n;j++)
		{
			for (ll k=j;k<=n;k++)
			{
				ll nxt=cards[k].r;
				if (cards[nxt].val==cards[a[j]].val) for (ll x=nxt;x!=0;x=cards[x].r) cards[x].l=0,cards[x].val=0,cards[x].r=0,flag=false;
			}
			if (flag) for (card k=cards[j];k.val!=0;k=cards[k.r]) if (k.r==0) k.r=a[j],cards[a[j]].val=a[j],cards[a[j]].l=k.val,cards[a[j]].r=0;
		}
		for (card j=cards[a[i]];j.val!=0;j=cards[j.r]) ans[j.val]++;
	}
	for (ll i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
