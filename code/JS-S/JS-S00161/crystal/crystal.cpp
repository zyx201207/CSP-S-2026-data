#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500005], ans=0;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    if(n>10000){
        cout << ceil(sqrt(m*2.0/(a[2]-a[1]))-0.5);
        return 0;
    }
    sort(a+1, a+n+1);
    for(int i=1; i<=n; i++){
        long long maxn=-1, p=0;
        for(int j=i; j<=n; j++){
            if(a[j]>maxn){
                p+=(j-i)*(a[j]-maxn);
                maxn=a[j];
            }else{
                p+=(maxn-a[j]);
            }
            if(p>m){
                ans=max(ans, 1LL*j-i);
                break;
            }
        }
    }
    cout << ans;
    return 0;
}