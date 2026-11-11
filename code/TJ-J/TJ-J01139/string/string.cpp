#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
int t=1;
const int N=2e5+50;
int n,nw;
struct Piece
{
	char c;int cnt;
}a[N];
ll ans=0;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].cnt>>a[i].c;
	for(int L=1,R=n;L<R;)
	{
		nw=min(a[L].cnt,a[R].cnt);
		a[L].cnt-=nw;a[R].cnt-=nw;
		if(a[L].c!=a[R].c)ans+=nw;
		if(a[L].cnt==0)L++;
		if(a[R].cnt==0)R--;
	}
	cout<<ans<<'\n';
	return ;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
//	cin>>t;
	while(t--)solve();
	return 0;
}

