#ifndef SUBWAY_CPP_INCLUDED
#define SUBWAY_CPP_INCLUDED
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
int rd(){
    int x=0,k=1;
    char ch=getchar();
    while (ch<'0'||ch>'9'){
        if (ch=='-') k=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9'){
        x=x+(ch-'0');
        ch=getchar();
    }
    return k*x;
}
void wr(int x){
    if (x<0){
        putchar('-');
        x=-x;
    }
    if (x>9) wr(x/10);
    putchar(x%10+'0');
}
int c,n,m,d,q;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=rd();
    n=rd();
    m=rd();
    d=rd();
    q=rd();
    vector<int> w(m+1);
    vector<vector<pair<int,int> > >a(m+1);
    vector<vector<int> > dis(m+1,vector<int>(m+1,inf));
    for (int i=1;i<=m;i++) cin>>w[i];
    for (int i=1;i<=n;i++){
        int k=rd();
        int u=rd();
        int t=rd();
        for (int j=1;j<k;j++){
            int v=rd();
            if (dis[u][v])
            dis[u][v]=min(dis[u][v],t);
            t=rd();
            u=v;
        }
    }
    for (int i=1;i<=n;i++) dis[i][i]=0;
    for (int i=1;i<=m;i++){
        for (int j=1;j<=m;j++){
            for (int k=1;k<=m;k++){
                int x1=dis[i][k];
                int x2=dis[k][j];
                dis[i][j]=min(dis[i][j],x1+x2);
            }
        }
    }
    while (q--){
        int x=rd();
        int y=rd();
        wr(dis[x][y]+w[x]+w[y]);
        putchar('\n');
    }
    return 0;
}



#endif // SUBWAY_CPP_INCLUDED
