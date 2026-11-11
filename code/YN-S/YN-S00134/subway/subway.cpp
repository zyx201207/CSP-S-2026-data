#include <bits/stdc++.h>
using namespace std;
const int N=5e5+114;
int c,n,m,d,q;
long long w[N];
int a[N][26],cnt[N];
long long b[N][26];
long long dis[555][555];//dis[i][j] i号路线到j号路线的距离

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            dis[i][j]=1e18;
        dis[i][i]=0;
    }
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1,ids;j<=k;j++){
            long long t;
            cin>>ids>>t;
            cnt[ids]++;
            a[ids][cnt[ids]]=i;
            b[ids][cnt[ids]]=t;
        }
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=cnt[i];j++)
            for(int u=j+1;u<=cnt[i];u++){
                dis[a[i][j]][a[i][u]]=min(dis[a[i][j]][a[i][u]],b[i][j]+b[i][u]);
                dis[a[i][u]][a[i][j]]=dis[a[i][j]][a[i][u]];
            }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++){
            if(i==k)
                continue;
            for(int j=i+1;j<=n;j++){
                if(j==k)
                    continue;
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                dis[j][i]=dis[i][j];
            }
        }
    while(q--){
        int x,y;
        cin>>x>>y;
        long long ans=1e18;
        for(int j=1;j<=cnt[x];j++)
            for(int u=1;u<=cnt[y];u++)
                ans=min(ans,dis[a[x][j]][a[y][u]]+b[x][j]+b[y][u]);
        ans+=w[x]+w[y];
        cout<<ans<<"\n";
    }
    return 0;
}

//    freopen("subway.in","r",stdin);
//    freopen("subway.out","w",stdout);


/*
这期神了，
c,n,m,d,q
让我看成，
c,n,m,d,p
我还以为出题人魔了
话说T3是DP吗
*/
