#include <bits/stdc++.h>
using namespace std;
long long a[500050], m, n;
bool check(long long i, long long mid){
    long long ans = 0;
    for(i; i < mid; i++){
        ans = ans + a[mid] - a[i];
    }
    if(ans <= m){
        return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(long long i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    long long c = a[2] - a[1];
    bool flag = 1;
    for(long long i = 3; i <= n; i++){
        if(a[i] - a[i-1]!=c){
            flag = 0;
            break;
        }
    }
    if(flag){
        long long t = 0;
        for(long long i = 1; i < n; i++){
            if(t+i*c <= m){
                t+=i*c;
            }else{
                cout << i;
                return 0;
            }
        }
    }
    long long cnt = 0;
    for(long long i = 1; i <= n; i++){
        if(a[i]==a[i-1]){
            continue;
        }
        long long l = i, r = n, mid;
        while(l <= r){
            mid = (l+r) / 2;
            if(check(i, mid)){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        for(long long i = l; i <= n;i++){
            if(a[i]==a[l-1]){
                l++;
            }else{
                break;
            }
        }
        cnt = max(cnt, l-i);
    }

    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
