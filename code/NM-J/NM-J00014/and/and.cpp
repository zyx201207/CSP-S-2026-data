#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10010][10010],b[10010],c[10010],n,m,x,maxa=0;
void dfs(ll x,ll k)
{
	
}
int main()
 {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll i,j,s,k,o,x,y,u;
	cin>>n>>m;
	for(i=1;i<=n;++i) cin>>c[i];
	sort(c+1,c+1+n);
	if(m==1)
	{
		cout<<c[n];
		return 0;
	}
	else cout<<"0";
	return 0;
}
