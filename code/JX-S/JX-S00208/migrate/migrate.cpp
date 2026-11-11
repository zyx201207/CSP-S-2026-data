#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e3+5,M=2e6+5;
int c,T,n,m;
int a[M],f[M],g[M];

void solve1(){
    for(int i=1;i<=n;i++) f[i]=g[i]=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        g[i]=1;
        for(int j=i+1;j<=n;j++){
            int id=lower_bound(a+i,a+n+1,a[j]-m)-a;
            f[j]=f[id]+1;
            if(g[id]==1){
                if(id+1>=j||f[id+1]!=f[id]) g[j]=1;
                else if(id+2>=j||f[id+2]!=f[id]) g[j]=2;
                else g[j]=3;
            }
            if(g[id]==2){
                if(id+1>=j||f[id+1]!=f[id]) g[j]=2;
                else g[j]=3;
            }
            if(g[id]==3) g[j]=3;
            if(g[j]==2) ans++;
        }
    }
    cout<<ans<<"\n";
}

void solve2(){
    int ans=0;
    for(int i=1;i<=n;i++) f[i]=g[i]=0;
    g[1]=1;
    for(int j=2;j<=n;j++){
        int id=lower_bound(a+1,a+n+1,a[j]-m)-a;
        f[j]=f[id]+1;
        if(g[id]==1){
            if(id+1>=j||f[id+1]!=f[id]) g[j]=1;
            else if(id+2>=j||f[id+2]!=f[id]) g[j]=2;
            else g[j]=3;
        }
        if(g[id]==2){
            if(id+1>=j||f[id+1]!=f[id]) g[j]=2;
            else g[j]=3;
        }
        if(g[id]==3) g[j]=3;
        if(g[j]==2) ans+=(n-j+1);
    }
    cout<<ans<<"\n";
}

void solve3(){
    cout<<0<<"\n";
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        if(c<=10) solve1();
        else if(c>=11&&c<=12) solve2();
        else solve3();
    }
    return 0;
}