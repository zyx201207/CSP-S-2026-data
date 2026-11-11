#include <bits/stdc++.h>
#define ll long long
using namespace std;

// the one who cant change the shu ru fa
// the one who once mistook folder name
// at the edge of zero point
// 15:17 wan le wan le zen me jia le
// 15:26 omg actually shu zu kai xiao le
// mei beng zhu
// Fortunately sheng xing duo yi one place forget long long
// 4 examples passed
// hope for 100pts

// Again and again I sighed.

const int MAXN = 500100;

int n,ans = 1;
ll m,a[MAXN],sum[MAXN];

int check(int t){
    int l = 1,r = t,mid;
    
    while(l<r){
        mid = (l+r)>>1;
        // if(t == 4){
        //     printf("from %d to %d sum %d comp %c",mid,t,a[t]*(t-mid+1),c)
        // }
        if(a[t]*(t-mid+1)-sum[t]+sum[mid-1]<=m){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    return t-r+1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin >> n >> m;

    for(int i = 1;i<=n;i++) cin >> a[i];

    sort(a+1,a+1+n);

    for(int i = 1;i<=n;i++){
        sum[i] = sum[i-1]+a[i];
        // cout << sum[i] << " ";
    }
    // cout << "\n";

    for(int i = 1;i<=n;i++){
        ans = max(ans,check(i));
        // printf("try %d get %d\n",i,check(i));
    }

    printf("%d\n",ans);

    return 0;
}