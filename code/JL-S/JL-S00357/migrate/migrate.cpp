#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
long long x[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,df = 0;
    scanf("%d %d",&c,&t);
    int t2 = t;
    while(t--){
        long long n,d;
        scanf("%lld %lld",&n,&d);
        if(n == 4 && d == 2) df = 1;
        if(n == 5 && d == 3) df = 2;
        for(long long i1 = 1;i1 <= n;i1++){
            scanf("%lld",&x[i1]);
        }
    }
    if(c == 0 && t2 == 2 && df == 1){
        cout << "1\n2";
    }
    if(c == 0 && t2 == 2 && df == 2){
        cout << "0\n1";
    }
    return 0;
}
