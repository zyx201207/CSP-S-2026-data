#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,d,wei[2200005];
int nxt[2200005],dp[2100005][5][5],vis[2100005][5][5],Ans;
int solve(int id1,int id2,int id3){
    int R3=nxt[id3];
    if(R3==id3){
        return 0;
    }
    int c1=0,c2=0;
    if(id1==0){
        c1=0;
    }else {
        c1=id3-id1+1;
    }
    if(id2==0){
        c2=0;
    }else{
        c2=id3-id2+1;
    }
    if(vis[id3][c1][c2]){
        return dp[id3][c1][c2];
    }
    int R2=0,R1=0;
    if(id2>=1){
        R2=nxt[id2];
    }
    if(id1>=1){
        R1=nxt[id1];
    }
    int W=0;
    if(id2==0){
        W=0;
    }else if(id1==0){
        W=max(R2-id3,0ll);
    }else{
        if(R2<=id3){
            W=0;
        }else{
            W=R2-max(id3,R1);
        }
    }
    int Nxt1=max(R1,max(R2-1,R3-2)),Nxt2=max(R2,R3-1),Nxt3=R3;
    if(Nxt1<=id3){
        Nxt1=0;
    }
    if(Nxt2<=id3){
        Nxt2=0;
    }
    if(R2>id3 && R2==R3-1){
        Nxt1=R2;
    }
    vis[id3][c1][c2]=1;
    dp[id3][c1][c2]=W+solve(Nxt1,Nxt2,R3);
    return dp[id3][c1][c2];
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--){
        Ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>wei[i];
            nxt[i]=0;
            for(int j=0;j<=4;j++){
                for(int j1=0;j1<=4;j1++){
                    dp[i][j][j1]=0;
                    vis[i][j][j1]=0;
                }
            }
        }
        int N=n;
        for(int i=n;i>=1;i--){
            while(wei[N]-wei[i]>d){
                N--;
            }
            nxt[i]=N;
        }
        for(int i=1;i<=n;i++){
            Ans+=solve(0,0,i);
        }
        cout<<Ans<<'\n';
    }
    return 0;
}