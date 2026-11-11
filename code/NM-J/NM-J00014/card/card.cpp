#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000010];
int main()
 {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        freopen("card.in","r",stdin);
        freopen("card.out","w",stdout);
        ll i,m,n,x;
        cin>>n>>m;
        for(i=1;i<=n;++i) cin>>x,a[x]++;
        for(i=1;i<=m;++i) if(a[i]!=0) cout<<a[i]<<" ";
        return 0;
}
