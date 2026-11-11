#include<bits/stdc++.h>
#define int long long

int N,M;
int arr[500005];
int pre[500005];

bool check(int mid){
    for(int i=mid;i<=N;i++){
        int tmp = arr[i]*mid-(pre[i]-pre[i-mid]);
        if(tmp <= M)return true;
    }
    return false;
}

void solve(){
    scanf("%lld %lld",&N,&M);
    for(int i=1;i<=N;i++)scanf("%lld",arr+i);
    std::sort(arr+1,arr+N+1);
    for(int i=1;i<=N;i++)pre[i] = pre[i-1]+arr[i];
    int l = 1,r = N,ans = -1;
    while(l <= r){
        int mid = (l+r)>>1;
        if(check(mid)){
            ans = mid; l = mid+1;
        }else r = mid-1;
    }
    printf("%lld\n",ans);
}

signed main(){
    freopen("crystal.in","r",stdin); freopen("crystal.out","w",stdout);
    solve();
    return 0;
}
