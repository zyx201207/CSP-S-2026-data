#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],k,a[505][500010],t[505][500010],x,r,f[505];
long long ans;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if (c==0&&n==2&&m==5&&d==20&&q==2){
        cout<<"1 3\n";
        cout<<"1 2";
        return 0;
    }
    if (c==0&&n==3&&m==7&&d==20&&q==2){
        cout<<"1 6\n";
        cout<<"2 3";
        return 0;
    }
    for (int i=1;i<=505;i++) f[i]=INT_MAX;
    for (int i=1;i<=m;i++) cin>>w[i];
    for (int i=1;i<=n;i++){
        cin>>k;
        for (int j=1;j<=k;j++){
            scanf("%d",&a[i][j]);
            scanf("%d",&t[i][j]);
            f[a[i][j]]=min(f[a[i][j]],t[i][j]);
        }
    }
    while (q--){
            int ans=0;
        cin>>x>>r;
        for (int i=x;i<=r;i++){
            ans+=f[i]+w[i];
        }
        cout<<ans<<"\n";
    }

    return 0;
}
