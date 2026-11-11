#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long cnt = 1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n , m;
    scanf("%lld%lld",&n,&m);
    for(int i = 1 ; i <= n ; i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1 , a+n+1);
    for(int i = 1 ; i <= n ; i++){
        long long t = (a[i+1] - a[i])*i;
        if(m-t >= 0){
            m -= t;
            cnt++;
        }
        else if(m-t < 0){
            printf("%lld" , cnt);
            return 0;
        }
    }
    return 0;
}
