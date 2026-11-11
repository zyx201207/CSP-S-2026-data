#include<bits/stdc++.h>
using namespace std;
int a[100001], b[1000001], c[100001], d[100001];
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    int cnt = 0;
    for(int i = 1; i<=n; i++){
        for(int j = i; j<=n; j++){
            b[a[j]]++;
            if(b[a[j]] == 2){
                b[a[j]] = 1;
                for(int k = cnt; k>=1; k--){
                    cnt--;
                    if(c[cnt+1] == a[j]){
                        break;
                    }
                }
            }
            c[++cnt] = a[j];
        }
        for(int j = 1; j<=cnt; j++){
            d[c[j]]++;
        }
        for(int j = 1; j<=m; j++){
            b[j] = 0;
        }
        cnt = 0;
    }
    for(int i = 1; i<=m; i++){
        cout << d[i] << ' ';
    }
    return 0;
}