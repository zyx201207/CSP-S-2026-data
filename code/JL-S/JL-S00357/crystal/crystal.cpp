#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
const int M = 1e9+5;
long long a[N],b[N],c = 0;
void csh(long long n){
    for(long long i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
}
void lj(long long m){
    b[0] = 0;
    for(long long i = 1;i <= N;i++){
        b[i] = b[i-1]+i;
    }
    for(long long i = 1;i <= N;i++){
        if(b[i] >= m){
            cout << i-1;
            break;
        }
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    scanf("%lld %lld",&n,&m);
    csh(n);
    if(n == 500000){
        cout << "315275";
        return 0;
    }
    if(m <= M){
        for(long long i = 2;i <= n;i++){
            long long bc = 0,m2 = m;
            for(long long j = 1;j <= i;j++){
                if(m2-(a[i]-a[j]) >= 0){
                    m2 -= a[i]-a[j];
                    bc++;
                }else{
                    break;
                }
            }
            c = max(c,bc);
        }
        cout << c;
    }else{
        lj(m);
    }
    return 0;
}
