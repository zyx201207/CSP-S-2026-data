#include<bits/stdc++.h>
using namespace std;
long long a[500007], s[500007], n, m;
bool check(int x, int y){
    long long p = (y-x+1)*a[y];
    long long q = s[y]-s[x-1];
    if(p-q > m) return false;
    return true;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    for(int i = 1; i <= n; i++){
        s[i] = s[i-1]+a[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int l = 1, r = i;
        while(l < r){
            int mid = (l+r)/2;
            if(check(mid,i)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        ans = max(ans, i-l+1);
    }
    cout << ans;
    return 0;
}
