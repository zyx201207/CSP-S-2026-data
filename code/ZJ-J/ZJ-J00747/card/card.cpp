 #include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e6+10;
ll n,m,a[N],tr[N],id[N],pre[N],ans[N],lst[N];
//void push_up(ll x)
//{
//	tr[x]=max(tr[x],max(tr[x<<1],tr[x<<1|1]));
//}
void push_down(ll x,ll l,ll r)
{
	if (l == r) return ;
	tr[x<<1]=max(tr[x<<1],tr[x]);
	tr[x<<1|1]=max(tr[x<<1|1],tr[x]);
	ll mid=(l+r)>>1;
	push_down(x<<1,l,mid);
	push_down(x<<1|1,mid+1,r);
}
void add(ll x,ll l,ll r,ll L,ll R,ll S)
{
//	cout << "{" << x << ' ' << l << ' ' << r << ' ' << L << ' ' << R << ' ' << S << "}" << endl;
	if (l >= L && r <= R)
	{
		tr[x]=max(tr[x],S);
		return ;
	}
	ll mid=(l+r)>>1;
	if (L <= mid) add(x<<1,l,mid,L,R,S);
	if (R > mid) add(x<<1|1,mid+1,r,L,R,S);
}
ll query(ll x,ll l,ll r,ll X)
{
	if (l == r) return tr[x];
	ll mid=(l+r)>>1;
	if (X <= mid) return query(x<<1,l,mid,X);
	else return query(x<<1|1,mid+1,r,X);
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		pre[i]=id[a[i]];
		id[a[i]]=i;
	}
	add(1,1,n,1,n,1);
	for (ll i = 1; i <= n; i++)
	{
		ll p=pre[i];
		if (p == 0) continue;
		add(1,1,n,p+1,i-1,p+1);
//		cout << "[" << p << endl;
//		cout << endl;
	}
//	cout << "{{{ " << tr[1] << " }}}";
	push_down(1,1,n);
	for (ll i = 1; i <= n; i++)
	{
		ll qwq=query(1,1,n,i);
		ans[a[i]]+=max(0ll,i-max(lst[a[i]],qwq)+1);
		lst[a[i]]=(qwq<=i?i:0);
	}
	for (ll i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0; 
}
// I forget it.
// luogu: @people123
