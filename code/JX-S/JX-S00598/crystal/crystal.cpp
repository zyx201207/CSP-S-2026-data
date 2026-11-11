#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll cry[N],n,m,ans=1,nw[3],ma;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<=n-1;i++)cin>>cry[i];
    ll k=m;
    sort(cry,cry+n);
    nw[1]=cry[n-1];
    for(int i=n-2;i>=0;i--)
    {
      if(cry[i]==nw[1])
      {
          ans++;
          continue;
      }
    if(nw[2]==0)nw[2]=i;
    if(k-(nw[1]-cry[i])>=0)
    {
        k=k-nw[1]+cry[i];
        ans++;
        continue;
    }
    ma=max(ma,ans);
    k=m;
    i=nw[2];
    nw[2]=0;
    nw[1]=cry[i];
    ans=1;
    }
    max(ma,ans);
    cout<<ma;
    return 0;
}