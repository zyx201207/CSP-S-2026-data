#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
long long a[N];
int main(){
    freopen("end.in","r",stdin);
    freopen("end.out","w",stdout);
    long long n,m,ma = 0;
    cin >> n >> m;
    for(long long i = 1;i <= n;i++){
        cin >> a[i];
    }
    if(m == 1){
        cout << 0;
        return 0;
    }
    sort(a+1,a+1+n);
    if(m == 2){
        for(long long i = 1;i <= n-1;i++){
            for(long long j = i+1;j <= n;j++){
                ma = max(ma,a[i]&a[j]);
            }
        }
    }else if(m == n){
        ma = a[1];
        for(long long i = 2;i <= n;i++){
            ma &= a[i];
        }
    }
    cout << ma;
    return 0;
}
