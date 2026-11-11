#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+3;
int c,T,n,d;
int a[N];
bool check(int l,int r){
    if(a[r]-a[l]<=d)return false;
    int acnt=0;
    for(int i=l+1;i<=r-1;i++){
        if(a[i]-a[l]<=d&&a[r]-a[i]<=d)acnt++;
    }
    if(acnt==2)return true;
    return false;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&T);
    while(T--){
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        if(c<=6){
            int cnt=0;
            for(int i=1;i<=n;i++){
                for(int j=i+3;j<=n;j++){
                    if(check(i,j))cnt++;
                }
            }
            printf("%lld\n",cnt);
        }
    }
    return 0;
}

