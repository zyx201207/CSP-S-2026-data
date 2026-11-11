#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,Min=9999999;
int w[1000000001];
int a[1000000001][1000000001],t[1000000001][1000000001];
int k[1000000001],x,y;
struct L{
    int tt,lt=1,nt=1;
    int next[1000001];
    int last[1000001];
}p[1000000001];
long long dfs(int dp,int x,int y){
    if(x==y&&Min<dp){
        return dp;
    }
    for(int i=1;i<=p[x].nt;i++){
        return dfs(dp++,p[x].next[i],y);
    }

}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            p[a[i][j]].tt=t[i][j];
            if(j>1){
                p[a[i][j]].last[p[a[i][j]].lt++]=a[i][j-1];
                p[a[i][j]].next[p[a[i][j]].nt++]=a[i][j+1];
            }else if(j==1){
                p[a[i][j]].next[p[a[i][j]].nt++]=a[i][j+1];
            }else{
                p[a[i][j]].last[p[a[i][j]].lt++]=a[i][j-1];
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        cout<<dfs(0,x,y);
    }

    fclose(stdin);
    fclose(stdout);



    return 0;
}
