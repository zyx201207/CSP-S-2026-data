#include <bits/stdc++.h>
using namespace std;
long long n, m, ans, f, ji, he, jia;
long long a[500010];
void toufen(){
    long long cha = a[2] - a[1];
    jia += cha;
    while(true){
        if(he + jia <= m){
            he += jia;
            jia += cha;
            ans++;
        }else{
            break;
        }
    }
    cout << ans + 1;
    return;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a, a + n + 1);
    if(n > 5000){
        toufen();
        return 0;
    }
    for(int i = 1;i <= n;i++){
        f = 0;
        ji = 0;
        for(int j = i - 1;j > 0;j--){
            f += a[i] - a[j];
            if(f <= m){
                ji++;
            }
        }
        if(ji != 0){
            ji++;
        }
        ans = max(ji, ans);
    }
    cout << ans;
    return 0;
}
