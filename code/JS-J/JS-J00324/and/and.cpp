#include<bits/stdc++.h>
using namespace std;
bool a[200005][35];
bool s[200005][35];
bool c[200005];
int main(){
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    int n , m;
    cin >> n >> m;
    long long b;
    int maxn = 0;
    for(int i = 1 ; i <= n ; i++){
        cin >> b;
        int num = -1;
        while(b){
            num++;
            if(b % 2 == 1){
                a[i][num] = 1;
            }
            b /= 2;
            maxn = max(maxn , num);
        }
    }
    int flag = 0;
    int cnt = 0;
    long long ans = 0;
    for(int i = maxn ; i >= 0 ; i--){
        cnt = 0;
        for(int j = 1 ; j <= n; j++){
             c[j] = 0;
        }
        for(int j = 1 ; j <= n; j++){
            if(flag == 0){
                if(a[j][i] == 1){
                    c[j] = 1;
                    cnt++;
                }
            }
            else{
                if(a[j][i] == 1 && s[j][i+1] == 1){
                    c[j] = 1;
                    cnt++;
                }
            }
        }
        if(cnt < m){
            for(int j = 1 ; j <= n; j++){
                s[j][i] = s[j][i+1];
            }
        }
        else{
            flag = 1;
            for(int j = 1 ; j <= n; j++){
                 s[j][i] = c[j];
            }
            ans += pow(2 , i);
        }
    }
    cout << ans;
    return 0;
}
