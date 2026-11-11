#include<bits/stdc++.h>
#define int long long
#define N 1005
using namespace std;
int n,m,a[N];
pair<int,int> f[N][N];
int g[N][N],rr=2e18,ccnt=0;
void dfs(int u,int ed,int cnt){
    if(cnt>rr) return ;
    if(u==ed){
        if(rr>cnt) rr=cnt,ccnt=1;
        else if(rr==cnt) rr=cnt,ccnt++;
        return ;
    }
    for(int i=ed;i>=u+1;i--){
        if(a[i]-a[u]<=m){
            dfs(i,ed,cnt+1);
        }
        // else break;
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        int res=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                rr=8e18; ccnt=0;
                dfs(i,j,0);
                if(rr<=2e18&&ccnt==2) res++;
            }
        }
        cout<<res<<"\n";
        // int cnt=0;
        // for(int i=1;i<=n;i++){
        //     for(int j=i;j<=n;j++){
        //         int res=0;
        //         for(int k=i+2;k<=j;k++) if(f[i][k-1].first==f[i][k-2].first&&a[k]-a[k-1]<=m&&a[k]-a[k-2]<=m) res++;
        //         cout<<"---- "<<i<<" "<<j<<" "<<res<<"\n";
        //         if(res==1&&f[i][j].first<8e18) cnt++;
        //     }
        // }
        // int res=0;
        // for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) if(f[i][j].second==2) res++,cout<<i<<" "<<j<<"\n";
        // cout<<cnt<<"\n";
    }
}