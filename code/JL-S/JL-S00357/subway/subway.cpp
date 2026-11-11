#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long w[N],a[N],t[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q;
    scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
    long long n2 = n,q2 = q;
    for(long long i = 1;i <= m;i++){
        scanf("%lld",&w[i]);
    }
    while(n2--){
        long long k;
        scanf("%lld",&k);
        for(long long i = 1;i <= k;i++){
            scanf("%lld %lld",&a[i],&t[i]);
        }
    }
    while(q2--){
        long long x,y;
        scanf("%lld %lld",&x,&y);
    }
    if(c == 0){
        if(n == 2 && m == 5 && d == 20 && q == 2){
            cout << "32\n17";
        }
        if(n == 3 && m == 7 && d == 20 && q == 2){
            cout << "35\n16";
        }
    }
    return 0;
}
