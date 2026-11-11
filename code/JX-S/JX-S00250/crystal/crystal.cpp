#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 6;
int arr[N];
int pre[N];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n,m;
    scanf("%lld %lld",&n,&m);
    
    for(int i = 1;i <= n;i ++) scanf("%lld",&arr[i]);

    sort(arr + 1,arr + n + 1);

    for(int i = 1;i <= n;i ++) pre[i] = pre[i - 1] + arr[i];

    int ans = 1;
    for(int i = 2;i <= n;i ++){
        for(int j = 1;j < i;j ++){
            int sum = (i - j) * arr[i] - pre[i - 1] + pre[j - 1];
            if(sum <= m){
                ans = max(ans,i - j + 1);
                if(ans == n){
                    printf("%lld",n);
                    return 0;
                }
                break;
            }
        }
    }

    printf("%lld",ans);
    return 0;
}