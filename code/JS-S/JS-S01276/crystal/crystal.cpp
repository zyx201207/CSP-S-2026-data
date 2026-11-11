#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long m,n,a[500005],sum[500005];
long long ans;
int cmp(int a,int b){
    return a>b;
}
int check(int x){
    //cout << "check" << x << ' ';
    for(int i = 1;i+x-1 <=n;i++){
        long long n_s = x*a[i] - (sum[i+x - 1] -  sum[i - 1]);
        //cout << "ns" << n_s << ' ';
        if(n_s <= m&& n_s >=0 && (m - n_s)%x == 0){
            return  true;
        }
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i = 1;i <=n;i++){
        sum[i] = sum[i -1]+a[i];
    }
    /*for(int i = 1;i <=n;i++){
        for(int j = 1;i+j <=n;j++){
            if(a[i]*j-(sum[i+j]-sum[i]) == m){
                ans = max(ans,j+1);
            }
        }
    }*/
    long long l = 0,r = 5*1e5+5,mid;
    while(l < r){
        mid = (l+r)/2;
        //if(l%2==r%2&&l%r == 1)mid+1;
        //cout << l << ' ' << r << endl;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
