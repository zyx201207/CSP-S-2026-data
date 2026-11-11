#include <bits/stdc++.h>
using namespace std;
struct num{
    long long a;
    bool b[35];
}g[200005],lst[200005];
int n,m,top,tot,ans=2147483647;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>g[i].a;
        int cnt=0;
        int t=g[i].a;
        while(t){
            g[i].b[++cnt]=t%2;
            t/=2;
        }
        top=max(top,cnt);
    }
    for(int k=top;k>=1;k--){
        tot=0;
        for(int i=1;i<=n;i++) if(g[i].b[k]==1) lst[++tot]=g[i];
        if(tot>=m){
            n=tot;
            for(int i=1;i<=n;i++) g[i]=lst[i];
            if(tot==m) break;
        }
    }
    for(int i=1;i<=m;i++)ans&=g[i].a;
    cout<<ans;
    return 0;
}
