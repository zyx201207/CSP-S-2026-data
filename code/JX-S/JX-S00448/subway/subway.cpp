#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int c,n,m,d,q,w[500010],k[510],a[510][500010],t[510][500010],ans=1e9,vis[500010],sum,x,y;

int dg(int now1,int now2){
    if(a[now1][now2]==y){
        ans=min(ans,sum);
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            if(vis[a[i][j]]) continue;
            if(now1!=i && a[now1][now2]!=a[i][j]) continue;
            vis[a[i][j]]=1;
            if(i!=now1){
                sum+=(t[now1][now2]+t[i][j]);
            }
            if(a[now1][now2]!=a[i][j]){
                sum+=(t[now1][now2]+t[i][j]);
            }
            dg(i,j);
            vis[a[i][j]]=0;
            if(i!=now1){
                sum-=(t[now1][now2]+t[i][now2]);
            }
            if(a[now1][now2]!=a[i][j]){
                sum-=(t[now1][now2]+t[i][j]);
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++) cin >> w[i];
    for(int i=1;i<=n;i++){
        cin >> k[i];
        for(int j=1;j<=k[i];j++){
            cin >> a[i][j] >> t[i][j];
        }
    }

    while(q--){
        ans=0;
        cin >> x >> y;
        int temp1,temp2;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=2;j++){
                if(a[i][j]==x){
                    temp1=i;
                    temp2=j;
                }
            }
        }

        dg(temp1,temp2);
        ans+=w[x]+w[y];
        ans+=t[temp1][temp2];
        cout << ans << endl;
        ans=1e9;
    }




    return 0;
}
