#include<bits/stdc++.h>
using namespace std;

long long n , m , a[500005] , sum[500005] , ans = 1;

long long ef(int i){
    int left = 1 , right = i;
    while(left < right){
        int mid = (left + right) / 2;
        long long q = a[i] * (i - mid + 1) - sum[i] + sum[mid - 1];
        if(q <= m){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return i - left + 1;
}

int main(){
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    sort(a + 1 , a + n + 1);
    for(int i = 2 ; i <= n ; i ++){
        ans = max(ans , ef(i));
    }
    cout << ans;
    return 0;
}
