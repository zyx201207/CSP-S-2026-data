#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,ans;
int a[N];
int tr[N];
void modify(int x,int y){for(;x<=n;x+=x&(-x))tr[x]+=y;return;}
int query(int x){int y=0;for(;x;x-=x&(-x))y+=tr[x];return y;}
int qry(int l,int r){return query(r)-query(l-1);}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		modify(i,a[i]);
		int l=1,r=i;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-qry(mid,i)<=m)r=mid;
			else	l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<"\n";
	return 0;
}