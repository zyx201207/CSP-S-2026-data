#include <bits/stdc++.h>
using namespace std;

int n,t;
long long a[200010];
int ans;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&t);
    for (int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    sort(a + 1,a + n + 1);
    ans = a[1];
    if (t == n){
        for (int i = 2;i <= n;i++){
            ans &= a[i];
        }
        printf("%d",ans);
    }
    else {
        ans = a[n];
        for (int i = n - 1;i > n - t;i--){
            ans &= a[i];
            if (ans == 0){
                break;
            }
        }
        if (ans != 0)
            printf("%d",ans);
        else{
            printf("%lld",a[n - t]);
        }
    }
    return 0;
}
