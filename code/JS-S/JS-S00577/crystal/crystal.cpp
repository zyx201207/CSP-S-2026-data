#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int flag1=1;
    for(int i=1;i<=n;++i){
        if(a[i]!=i)
            flag1=0;
    }
    if(flag1){
        vector<int> pre(n+1);
        for(int i=1;i<=n;++i){
            pre[i]=pre[i-1]+a[i];
            if(pre[i]>m){
                cout<<i;
                return;
            }
        }
    }
    int flag2=0;
    int d=a[2]-a[1];
    for(int i=3;i<=n;++i){
        if(a[i]-a[i-1]!=d)
            flag2=0;
    }
    if(flag2){
        vector<int> x(n+1);
        for(int i=1;i<=n;++i){
            x[i]=d*i;
        }
        vector<int> pre1(n+1);
        for(int i=1;i<=n;++i){
            pre1[i]=pre1[i-1]+x[i];
            if(pre1[i]>m){
                cout<<i;
                return;
            }
        }
    }
    vector<vector<int> >c(n+1,vector<int>(n+1));
    for(int i=1;i<=n;++i){
        c[i][i]=0;
    }
    for(int i=1;i<n;++i){
        for(int j=i+1;j<=n;++j){
            c[i][j]=c[i][j-1]+(a[j]-a[j-1])*(j-1);
        }
    }
    int ma=0;
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            if((c[i][j]<=m)&&(j-i+1>ma))
                ma=j-i+1;
        }
    }
    cout<<ma;
    return;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
