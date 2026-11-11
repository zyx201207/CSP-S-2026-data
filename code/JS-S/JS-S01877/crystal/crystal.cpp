#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,ans,sum,lst;
int a[N],dp[N],add[N];
void prep();
void init();
void dr();
void work();
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int T=1;
//    cin>>T;
    prep();
    while(T--){
        init();
        dr();
        work();
    }
    return 0;
}
void prep(){
}
void init(){
}
void dr(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
}
void work(){
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int need=(i-1-lst)*(a[i]-a[i-1]);
        for(;lst<i-1;lst++){
            if(m-sum>=need) break;
            need-=a[i]-a[i-1];
            sum-=a[i-1]-a[lst];
        }
        sum+=need;
        //cout<<i-lst<<'\n';
        ans=max(ans,i-lst);
    }
    cout<<ans;
}
