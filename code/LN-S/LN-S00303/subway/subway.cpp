#include<bits/stdc++.h>
#define int long long
using namespace std;
//第二题请忽略公式部分（）
struct edge{
    int num;
    int p;
    int next;
};

edge e[4000100];
int head[2000100];
int x1;

void add(int x,int y,int z){
    x1++;
    e[x1].num=y;
    e[x1].p=z;
    e[x1].next=head[x];
    head[x]=x1;
}

int c,n,m,d,q;
int ma[610][610];
int w[2000100];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    for(int i=1;i<=n;i++){
        int ki;
        cin >> ki;
        for(int j=1;j<=ki;j++){
            int u,v;
            cin >> u >> v;
            add(u,i,v);
        }
    }
    memset(ma,0x3f,sizeof(ma));
    for(int i=1;i<=m;i++){
        for(int it1=head[i];it1!=0;it1=e[it1].next){
            for(int it2=head[i];it2!=it1;it2=e[it2].next){
                ma[e[it1].num][e[it2].num]=min(ma[e[it1].num][e[it2].num],e[it1].p+e[it2].p);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ma[i][j]=min(ma[i][j],ma[j][i]);
            if(i==j){
                ma[i][j]=0;
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ma[i][j]=min(ma[i][j],ma[i][k]+ma[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int ans=0x3f3f3f3f3f3f3f;
        int u,v;
        cin >> u >> v;
        for(int it1=head[u];it1!=0;it1=e[it1].next){
            for(int it2=head[v];it2!=0;it2=e[it2].next){
                ans=min(ans,e[it1].p+e[it2].p+ma[e[it1].num][e[it2].num]);
            }
        }
        cout << ans+w[u]+w[v] << '\n';
    }
    return 0;
}
