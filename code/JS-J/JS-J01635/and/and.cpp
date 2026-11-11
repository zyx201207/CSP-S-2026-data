#include<bits/stdc++.h>
using namespace std;

bool is2N(int a){
    bool flag = 1;
    while(a % 2 == 0){
        a /= 2;
    }
    if(a != 1){
        flag = 0;
    }
    return flag;
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    bool flag = 1;
    cin >> n >> m;
    int a[n + 1], mx = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > mx){
            mx = a[i];
        }
        if(!is2N(a[i])){
            flag = 0;
        }
    }
    if(n == m){
        int ans = a[0] & a[1];
        for(int i = 2; i < n; i++){
            ans = ans & a[i];
        }
        cout << ans;
    }else if(m == 1){
        cout << mx;
    }else if(m == 2){
        int mx2 = 0;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                mx2 = max(mx2, a[i] & a[j]);
            }
        }
        cout << mx2;
    }else if(flag){
        int b[n + 1];
        for(int i = 0; i < n; i++){
            b[i] = a[i];
        }
        sort(b, b + n);
        cout << b[n - m];
    }
    return 0;
}
