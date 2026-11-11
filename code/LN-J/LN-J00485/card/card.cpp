#include <bits/stdc++.h>
using namespace std;
int n , m;
int a[500020];
int cnt;
int main(){
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    bool flag = false;
    int mxb = 0;
    while(n - 1){
        cnt = 0;
        int xb = 1;
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= n;j ++){
                if(a[j] == a[i]){
                    flag = true;
                    a[i + 1] = a[j];
                    mxb = i + 1;
                }else{
                    a[n + 1] = a[j];
                    mxb = n + 1;
                }
            }
            for(int j = 1;j <= mxb;j ++){
                if(a[j] == a[i]){
                    cnt ++;
                }
            }
        }n--;
    cout << cnt << " ";
    }

    return 0;
}
