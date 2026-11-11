#include <bits/stdc++.h>
using namespace std;
long long a[500005], pre[500005];
int maxx = -1;
bool cmp(int a, int b){
    return a > b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);    cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int n;
    long long m;
    cin >> n >> m;
    a[0] = pre[0] = 0;
    //a[n+1] = -1e16;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    sort(a+1, a+n+1, cmp);
    for (int i = 1; i <= n+1; i ++){
        pre[i] = pre[i-1] + a[i];
    }
    for (int i = 1; i <= n; i ++){
        int l = i, r = n;
        int mid, len;
        while (l <= r){
            mid = (l+r)/2;
            len = mid-i+1;
            long long need = a[i]*len - (pre[mid]-pre[i-1]);
            if (need == m) {
                break;
            }else if (need < m){
                l = mid+1;
            }else {
                r = mid-1;
            }
        }
        long long need = a[i]*len - (pre[mid]-pre[i-1]);
        if (need > m) mid --;

        len = mid-i+1;
        maxx = max(maxx, len);
    }
    cout << maxx;

    return 0;
}

//__int 128 rp; rp ++;
//I love CCF
//I hope to AC.But AK is better!

/*

T1
14:50  find  zhengjie!!!!!!!!!!
15:15  debug
15:45  AC T1
*/
