#include<bits/stdc++.h>
using namespace std;
int n;
int c,m,d,q;
int w[500005];
long long wt[505][505];
int a[500005][25],tot[500005],t[500005][25];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int t1,t2;
            scanf("%d%d",&t1,&t2);
            a[t1][++tot[t1]]=i;
            t[t1][tot[t1]]=t2;
        }
    }for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            wt[i][j]=1000000000000000000ll;
        }wt[i][i]=0;
    }for(int i=1;i<=m;i++){
        for(int j=1;j<tot[i];j++){
            for(int k=j+1;k<=tot[i];k++){
                wt[a[i][j]][a[i][k]]=min(wt[a[i][j]][a[i][k]],0ll+t[i][j]+t[i][k]);
            }
        }
    }for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            wt[i][j]=wt[j][i]=min(wt[i][j],wt[j][i]);
        }
    }for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                wt[i][j]=min(wt[i][j],wt[i][k]+wt[k][j]);
            }
        }
    }while(q--){
        long long ans=1000000000000000000ll;
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        for(int i=1;i<=tot[t1];i++){
            for(int j=1;j<=tot[t2];j++){
                ans=min(wt[a[t1][i]][a[t2][j]]+t[t1][i]+t[t2][j],ans);
            }
        }
        ans+=w[t1]+w[t2];
        printf("%lld\n",ans);
    }
    return 0;
}