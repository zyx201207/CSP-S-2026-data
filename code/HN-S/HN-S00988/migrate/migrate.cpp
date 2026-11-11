#include <bits/stdc++.h>
#define lint __int128
#define int long long
#define Il inline
#define fi first
#define se second
#define vec vector
#define pb push_back
#define IT ::iterator
#define p_q priority_queue

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef double db;
const int N=2e6,M=5e3;
const db eps=1e-9;

// bool P1;

int testcase,T,n,m,a[N+5];
int f[N+5],q[N+5],g[N+5];

Il int brt(int r){
    int p=r,sm=1,ret=0;f[r]=0,g[r]=1;
    for(int i=r-1;i;i--){
        while(a[p]-a[i]>m){
            sm-=g[p--];
        }
        if(p<=i)break;
        if(sm<=0){
            sm=0;
            for(int j=p;j>i&&f[j]==f[p];j--){
                sm+=g[j];
            }
        }
        f[i]=f[p]+1,g[i]=sm;
        ret+=(g[i]==2);
    }
    return ret;
}

Il void solve1(){
    int ans=0;
    for(int i=n;i;i--){
        ans+=brt(i);
    }
    cout<<ans<<'\n';
    return;
}

Il void solve2(){
    return;
}

Il void solve3(){
    int ps=1,ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]-a[1]<=m&&a[n]-a[i]<=m){
            ps=i;break;
        }
    }
    if(ps==n||ps==1){
        cout<<"0\n";
        return;
    }
    int t=upper_bound(a+1,a+n+1,a[ps-1]+m)-a;
    for(int i=1;i<ps;i++){
        int po=upper_bound(a+1,a+n+1,a[i]+m)-a-1;
        if(po>ps+1)continue;
        if(po==ps+1){
            ans+=n-t+1;
        }
        if(po==ps){
            if(i==ps-1){
                ans+=t-1-ps;
            }else{
                int pt=upper_bound(a+1,a+n+1,a[ps-2]+m)-a;
                ans+=t-1-pt+1;
            }
        }
    }
    cout<<ans<<'\n';
    return;
}

Il void yuanshenqidong(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(testcase<=10){
        solve1();
    }else if(testcase<=12){
        solve2();
    }else if(testcase<=14){
        solve3();
    }
    return;
}

// bool P2;

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // cout<<abs((&P1)-(&P2))/1024/1024;return 0;
    cin>>testcase>>T;
    while(T--){
        yuanshenqidong();
    }
    return 0;
}
/*
*/