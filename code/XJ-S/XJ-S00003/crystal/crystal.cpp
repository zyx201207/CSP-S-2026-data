#include<bits/stdc++.h>
using namespace std;


long long n, m, ans;


int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    vector<long long> sj(n);
    for(long long i = 0; i < n; i++) cin >> sj[i];

    sort(sj.begin(), sj.end());

    long long l = 0, r = n-1;

    while(l <= r){
        long long mid = (l + r) / 2, cot = 0;
        //只用考虑小的补齐
        for(long long i = 0; i < mid; i++){
            cot += sj[mid] - sj[i];
        }
        if(cot <= m){
            ans = mid+1;
            l = mid + 1;
        }else{
            r = mid -1;
        }
    }

    cout << ans;

    return 0;
}
