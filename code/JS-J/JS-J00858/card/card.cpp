#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m;
long long jl[300005],ans[300005];
long long cnt[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    bool f = 1;
    for(long long i = 1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
        if(a[i]<a[i-1]) f = 0;
    }
    if(m == 1){
        cout<<n;
        return 0;
    }
    if(f){
        for(long long i = 1;i<=n;i++){
            cnt[a[i]]--;
            if(cnt[a[i]] == 0){
                ans[a[i]] = i;
            }
        }
        for(long long i = 1;i<=m;i++) cout<<ans[i]<<" ";
        return 0;
    }
    for(long long i = 1;i<=n;i++){
        for(long long j = 1;j<=m;j++){
            jl[j] = 0;
        }
        for(long long j = i;j<=n;j++){
            if(jl[a[j]] == 0){
                jl[a[j]] = j;
            }
            else{
                for(long long k = jl[a[j]];k<j;k++) jl[a[k]] = 0;
                jl[a[j]] = j;
            }
        }
        for(long long j = 1;j<=m;j++){
            ans[j]+=(jl[j]!=0);
        }
    }
    for(long long i = 1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
