#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long n,m,a[N],s[N],ans,cnt[N];
int tj;
/*
long long sum=0,q=0,p=0;
    if(r-l <= 3){
        for(int i = l;i <= r;i++){
            for(int j = 1;j <= n;j++){
                if(i - a[j] > 0)q += i-a[i];
            }
            if(q > sum && q <= m){
                sum = q;
                p=i;
            }
        }
        return p;
    }
*/
long long check(int l,int r){
    long long sum=0;
    if(l >= r){
        if(tj == 1)return l;
        else return r-1;
    }
    long long mid = (l+r) / 2  ;
    for(int i = 1;i <= n;i++){
        if(a[i] < mid){
            sum += mid-a[i];
        }
    }
    if(sum > m){
        tj = 1;
        return check(l,mid);
    }
    else if(sum == m)return mid;
    else {
        tj = 2;
        return check(mid+1,r);
    }
}
int main(){ //LLONG_MAX = 9e18
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    long long k = check(a[1] , a[n]);
    for(int i = 1;i <= n;i++){
        if(a[i] <= k)ans++;
    }
    cout << ans;
    return 0;
}
