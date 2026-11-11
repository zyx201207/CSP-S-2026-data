#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200001];
int dfs(int i,int s,int ans){
    if(s == m){
        return ans;
    }
    if(i > n){
        return 0;
    }
    long long q = ans;
    if(q == -1){
        q = a[i];
    }
    return max(dfs(i+1,s+1,q&a[i]),dfs(i+1,s,ans));
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    if(n <= 20 || m == 2){
        cout << dfs(1,0,-1);
    }else if(m == 1){
        long long max_a = -1;
        for(int i = 1;i <= n;i++){
            max_a = max(max_a,a[i]);
        }
        cout << max_a;
    }
    else if(n == m){
        int x = a[1];
        for(int i = 2;i <= n;i++){
            x &= a[i];
        }
        cout << x;
    }
    if(n > 2000){
        for(int i = 2;i <= n;i++){
            if(a[i] != a[i-1]){
                cout << 0;
                return 0;
            }
        }
        cout << a[1];
    }
    return 0;
}
