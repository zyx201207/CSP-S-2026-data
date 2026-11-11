#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool v[200005];
int ans;
void f(int x,int s,int p){
    if(x == m + 1){
        ans = max(ans,s);
    }
    for(int j = p;j <= n;j++){
        if(x + n - p < m){
            break;
        }
        if(!v[j]){
            v[j] = 1;
            f(x + 1,(s & a[j]),j);
            v[j] = 0;
        }
    }
}
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    int w = 1;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] != i - 1){
            w = 0;
        }
    }
    if(m == n){
        int r = a[1];
        for(int i = 2;i < n;i++){
            r &= a[i];
        }
        cout << r;
        return 0;
    }
    if(n > 2000){
        if(w){
            int e,f,g;
            for(int i = 1;i <= n && f <= n;i++){
                f *= 2;
                if(f == n){
                    g = i;
                }
            }
            for(int i = 1;i <= n;i++){
                f *= 2;
                if(f >= m){
                    for(int j = 1;j <= g - i;j++){
                        cout << 1;
                    }for(int j = i + 1;j <= g;j++){
                        cout << 0;
                    }
                }
            }
            return 0;
        }
        sort(a + 1,a + n + 1,cmp);
        for(int i = 1;i <= a[m];i++){
            cout << 1;
        }
        return 0;
    }
    for(int i = 1;i <= n;i++){
        v[i] = 1;
        f(2,a[i],i);
        v[i] = 0;
    }
    cout << ans;
    return 0;
}
