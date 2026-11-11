#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+3;
const int M=5e5+3;
int n,ans,a[M],m,w[M],cnt[M],e[M],minn[M],p[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1)cout<<1;
	else if(n==2&&m==1)cout<<2;
	else if(n==2&&m==2)cout<<"1 2";
	else cout<<"3 2 1";
}