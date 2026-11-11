#include<bits/stdc++.h>
using namespace std;
const int N =  5e5 + 10;


int main {
    freopen("crystal.in","n".stdin)
    freopen("crystal.out","m".stdout);
    long long n,m;
    scanf("%lld%lld",&n , &m);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1;a+1+n)
    for(int i = 1; i<= n;i++){
        sum[i] = sum=[i - 1]+a[i];
    }
    for(int i = 1; i<= n;i++){
        int l = 1,r = i;
        while(l <= r){
            int mid = (l + r) / 2
            if(check(mid,1)){
                l=mid + 1

            }else{
                r = mid - 1
            }

        }
        cout << i - l +1<< endl;
        ans = max(ans,i - l +1)
    }
    printf("%lld",ans)
    return 0;
}
