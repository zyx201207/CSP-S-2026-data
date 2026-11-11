#include<bits/stdc++.h>
using namespace std;
int kt[100010];
    const int INF=1e8;
    int t1[100010][100010],t[100010][100010];
    int tt[100010][100005];
    int n,c,m,d,q;
long long tot=0;
int main(){

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    //cin>>c>>n>>m>>d>>q;
    //         c-bianhao n-shulinag m-zhanshu d-maxjingguo q-jihua
    memset(t,INF,sizeof(t));
    for(int i=1;i<=m;i++){
            scanf("%d",&kt[i]);
    }
    for(int j=1;j<=n;j++){
        int x;
    scanf("%d",&x);
    for(int i=1;i<=x;i++){
        scanf("%d",tt[j][i]);
        scanf("%d",t[j][tt[j][i]]);
        t[tt[j][i]][j]=t[j][tt[j][i]];//=t1[tt[j][i]][j]=t1[j][tt[j][i]];
    }}
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=1;k<=n;k++){
                int lo=t[i][k]+t[k][j]+t[k][k];
                t[i][j]=t[j][i]=min(t[i][j],lo);
            }
        }
    }
    while(q--){
        int qd,md;
        scanf("%d %d",&qd,&md);
        int anss=kt[qd]+kt[md]+t[qd][md];
        printf("%d\n",anss);
    }
    return 0;
}
