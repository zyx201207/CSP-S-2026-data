#include <bits/stdc++.h>
using namespace std;
int n, ji, ans, shu;
int x1, x2;
unsigned long long a[200010], b[200010];
int c[200010];
char z[200010], zi[200010];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> c[i] >> z[i];
        a[i] = a[i-1] + c[i];
    }
    ji = 1;
    for(int i = n;i >= 1;i--){
        b[ji] = b[ji-1] + c[i];
        zi[ji] = z[i];
        ji++;
    }
    x1 = 1;
    x2 = 1;
    for(int i = 1;i <= (a[n]+1)/2;i++){
        if(a[x1] < i){
            x1++;
        }
        if(b[x2] < i){
            x2++;
        }
        if(z[x1] != zi[x2]){
            if(i < min(a[x1], a[x2])){
                ans += min(a[x1], a[x2]) - i + 1;
                i = min(a[x1], a[x2]);
            }else{
                ans++;
            }
        }else{
            if(i < min(a[x1], a[x2]))
            i = min(a[x1], a[x2]);
        }
    }
    cout << ans;
    return 0;
}
