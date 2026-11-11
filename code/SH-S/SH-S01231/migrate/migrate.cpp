#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[5086],dis[5086][5086],cnt;
void dfs1(long long from,long long now,long long y,long long depth){
    if(now==y){
        dis[from][y]=depth;
        return;
    }
    long long i=now+1;
    while(i<y){
        if(x[i]-x[now]>d){i--; break;}
        i++;
    }
    if(x[i]-x[now]>d){i--;}
    if(i==now) return;
    //cout<<"dfs1在"<<now<<"向"<<y<<"跳"<<i<<endl;
    dfs1(from,i,y,depth+1);
}
void dfs2(long long from,long long now,long long y,long long depth){
    if(now==y&&depth==dis[from][y]){
        cnt++;
        return;
    }
    if(depth>=dis[from][y]) return;
    long long i=now+1;
    while(i<=y){
        if(x[i]-x[now]>d){break;}
        //cout<<"dfs2在"<<now<<"向"<<y<<"跳"<<i<<endl;
        dfs2(from,i,y,depth+1);
        i++;
    }
    return;
}
void solve(){
    if(c==13 or c==14) cout<<0<<endl;
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            dfs1(i,i,j,0);
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<dis[i][j]<<" ";
        cout<<endl;
    }*/
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            cnt=0;
            dfs2(i,i,j,0);
            if(cnt==2) ans++;
        }
    cout<<ans<<endl;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++) solve();
    return 0;
}