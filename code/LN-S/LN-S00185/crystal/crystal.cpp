#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
int flag;
long long n,m,ans,a[MAXN];
void solve(int type){
    if(type == 1){
        if(m > n / 2){
            ans = (n / 2) - 1;
            return ;
        }
        else{
            ans = (n / 2);
            return ;
        }
    }
    else{
        if(m == 0) return ;
        if(m < n){
            if(m <= n / 2){
                ans = m;
                return ;
            }
            else if(m > n / 2){
                ans = m;
                return ;
            }
            return ;
        }
        else if(m == n){
            ans = (n / 2) + 1;
            return ;
        }
        else if(m > n){
            if(m < n * 2){
                ans = (n / 2 + 1);
                return ;
            }
            else{
                ans = n;
                return ;
            }
            return ;
        }
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
    sort(a + 1,a + n + 1);
    if(n % 2 == 0) flag = 1;
    else flag = 0;
    solve(flag);
    printf("%lld",ans);
    return 0;
}
