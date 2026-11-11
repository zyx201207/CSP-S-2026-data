#include<bits/stdc++.h>
#define int long long

int N,M;
int arr[200005];
bool vis[200005];
int pw[32];

void solve(){
    scanf("%lld %lld",&N,&M);
    pw[0] = 1;
    for(int i=1;i<32;i++)pw[i] = pw[i-1]*2;
    for(int i=1;i<=N;i++)scanf("%lld",arr+i);
    int ans = 0;
    for(int i=30;i>=1;i--){
        int cnt = 0;
        for(int j=1;j<=N;j++){
            if(vis[j])continue;
            if((arr[j]>>(i-1))&1)cnt++;
        }
        if(cnt >= M){
            for(int j=1;j<=N;j++){
                if(!((arr[j]>>(i-1))&1))vis[j] = 1;
            }
            //printf("%lld\n",i);
            ans += pw[i-1];
        }
    }
    printf("%lld\n",ans);
}

signed main(){
    freopen("and.in","r",stdin); freopen("and.out","w",stdout);
    solve();
    return 0;
}
//so ez T123?
