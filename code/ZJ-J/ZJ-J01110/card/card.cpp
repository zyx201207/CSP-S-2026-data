#include<bits/stdc++.h>
#define ll long long
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],sum[M],w[M],k=0,ans[M];
bool f[N];
int main()
{
  freopen("card.in","r",stdin);
  freopen("card.out","w",stdout);
  AC;
  cin>>n>>m;
  for(ll i=1;i<=n;i++)
  {
  	cin>>a[i];
  	sum[a[i]]++;
  	w[a[i]]=i;
  }
  sort(w+1,w+m+1);
  for(ll i=1;i<=m;i++)
  {
  	ll wz=w[i];
  	ans[a[wz]]+=sum[a[wz]];
  	sum[a[wz+1]]+=sum[a[wz]];
  }
  for(ll i=1;i<=m;i++)
  {
  	cout<<ans[i]<<" ";
  }
  return 0;
}
