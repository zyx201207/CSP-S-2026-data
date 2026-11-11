#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+2;
const int maxm=3e5+2;
int n,m;
int a[maxn],x[maxn],p[maxm],ans[maxm],cnt[maxn];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans[a[i]]+=i;
        x[p[a[i]]]=i;   // the next one which == a[i] (if no,x[i]=0)
        p[a[i]]=i;      // to record the latest a[i]'s number
    }
    for(int i=1;i<=n;i++){
        if(!x[i]) x[i]=i;
    }
    for(int i=1;i<=n;i++){
        int nw=i;
        while(nw<=n){
            cnt[nw]--;  //disappear number
            nw=x[nw];
            cnt[nw++]++;
        }
    }
    for(int i=1;i<=n;i++){
        cnt[i]+=cnt[i-1];
        ans[a[i]]+=cnt[i];
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
