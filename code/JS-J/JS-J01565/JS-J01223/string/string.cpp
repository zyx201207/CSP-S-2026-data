#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
int a[200010];
char c[200010];
int l = 0;
struct U{
    int left;
    int right;
}p[200010];
int k1 , m1;
int k2 , m2;
int ans = 0;

int f(int u){
    int cnt = 0;
    int lp = p[u].left - k1 + m1;
    int rp = p[u].right - k1 + m1;
    int idl = 0 , idr = 0;
    for(int i = u + 1;i <= n;i++){
        if(idl == 0 && p[i].left <= lp && p[i].right >= lp){
            idl = i;
        }
        if(idr == 0 && p[i].left <= rp && p[i].right >= rp){
            idr = i;
        }
        if(idl != 0 && idr != 0){
            break;
        }
    }
    for(int i = idl + 1;i <= idr - 1;i++){
        if(c[i] != c[u]){
            cnt += a[i];
        }
    }
    if(c[idl] != c[u]){
        cnt += p[idl].right - lp + 1;
    }
    if(c[idr] != c[u] && idl != idr){
        cnt += rp - p[idr].left + 1;
    }
    return cnt;
}

signed main(){
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    cin >> n;
//    int sum = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        cin >> c[i];
        p[i].left = l + 1;
        l += a[i];
        p[i].right = l;
    }
    if(l % 2 == 0){
        k1 = 1;
        k2 = l / 2;
        m1 = l / 2 + 1;
        m2 = l;
        for(int i = 1;i <= n;i++){
            if(p[i].right > k2){
                break;
            }
            ans += f(i);
        }
        cout << ans << endl;
    }else{
        k1 = 1;
        k2 = l / 2;
        m1 = l / 2 + 2;
        m2 = l;
        for(int i = 1;i <= n;i++){
            if(p[i].right > k2){
                break;
            }
//            sum++;
            ans += f(i);
        }
        cout << ans << endl;
    }
//    cout << sum << endl;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
