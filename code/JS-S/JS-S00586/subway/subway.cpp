#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=1e5+5;
int c,n,m,d,q,w[M],x[N],y[N];
long long s[1505][1505];
void dfs(int x,int y,long long sum){
    for(int i=x+1;i<=n+m;i++){
        if(s[x][i]>=sum+s[y][i]){
            s[x][i]=sum+s[y][i];
            s[i][x]=sum+s[y][i];
            dfs(x,i,sum+s[y][i]);
        }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    memset(s,0x3f,sizeof(s));
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int t0,t1,t2;
        cin>>t0;
        for(int j=1;j<=t0;j++){
            cin>>t1>>t2;
            s[m+i][t1]=t2;
            s[t1][m+i]=t2;
        }
    }
    for(int i=1;i<=m;i++){
        dfs(i,i,0);
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
        long long cnt=w[x[i]]+w[y[i]]+s[x[i]][y[i]];
        cout<<cnt;
        if(i!=q)cout<<endl;
    }
    return 0;
}
