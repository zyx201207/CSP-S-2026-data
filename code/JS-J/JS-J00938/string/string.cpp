#include <bits/stdc++.h>
using namespace std;
int a[10000000];
char c[10000000];
char d[100000000];
int main(){
    freopen("string.in";"r";stdin);
    freopen("string.out";"w";stdout);
    int n;cin >> n;
    int all;
    int cnt = 0;
    int ans = 0;
    for(int i = 1;i<=n;i++){
        cin >> a[i] >> c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            d[j+cnt] = c[i];
        }
        cnt += a[i];
    }

    for(int i=1;i<=n;i++){
        all += a[i];
    }
    if(all%2 == 0){
        for(int i=1;i<=all/2;i++){
            if(d[i] != d[all/2 + i]){
                ans += 1;
            }
        }
    }else{
        for(int i=1;i<=all/2;i++){
            if(d[i] != d[all/2 + i + 1]){
                ans += 1;
            }
        }

    }
    cout << ans;
    return 0;
}
