#include<bits/stdc++.h>
const int N=2e6+10;
using namespace std;
int c,t;
long long n,d;
long long x[N];
int getmin(int u,int v){
    int cnt=0;
    while(u!=v){
        int f=u+1;
        while(x[f]-x[u]<=d&&f<=v) f++;
        f--;
        if(f==u) return -1;
        u=f;
        cnt++;
    }
    return cnt;
}
int lj=0;
void dfs(int u,int v,int cnt,int mind){
    if(u==v){
        if(cnt==mind) lj++;
        return;
    }
    if(cnt>=mind||lj>2) return;
    for(int i=u+1;x[i]-x[u]<=d&&i<=v;i++){
        dfs(i,v,cnt+1,mind);
    }
}
void solve1(){
    //baoli
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int mind=getmin(i,j);
            if(mind==-1) break;
            lj=0;
            dfs(i,j,0,mind);
            if(lj==2) ans++;
        }
    }
    cout<<ans<<endl;
}
int dp1[505][505];
long long dp2[505][505];
void solve2(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp2[i][j]=0;
            dp1[i][j]=n+1;
        }
        dp1[i][i]=0;
    }
    for(int i=1;i<=n;i++) dp2[i][i]=1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j;x[j]-x[k]<=d&&k>=i;k--){
                dp1[i][j]=min(dp1[i][j],dp1[i][k]+1);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j;x[j]-x[k]<=d&&k>=i;k--){
                if(dp1[i][k]+1==dp1[i][j]) dp2[i][j]+=dp2[i][k];
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(dp2[i][j]==2) ans++;
        }
    }
    cout<<ans<<endl;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        if(n<=9){
            solve1();
            continue;
        }
        if(n<=500){
            solve2();
            continue;
        }
        bool A=1;
        for(int i=2;i<n;i++){
            if(x[i]-x[i-1]!=x[i+1]-x[i]){
                A=0;
                break;
            }
        }
        if(A){
            long long c=x[2]-x[1];
            long long s=d/c;
            if(s<=1) cout<<0<<endl;
            else{
                long long ans=n-2*s-1;
                cout<<max(ans,0ll)<<endl;
            }
            continue;
        }
    }
    return 0;
}
/*
10 35
0 7 14 21 28 35 42 49 56 63*/