#include <bits/stdc++.h>
using namespace std;

int a[500005];
int b[500005];
int num[300005];

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
            cin >> a[i];
    }
    for(int i = 0 ;i < n;i++){
        for(int j = i ;j < n;j++){
            b[j] = 0;
            for(int k = i;k < j;k++){
                if(a[j] == b[k]){
                    for(int l = i;l <= k;l++){
                        b[l] = 0;
                    }
                    break;
                }
            }
            b[j] = a[j];
        }
        for(int j = i;j < n;j++){
            for(int k = 1;k <= m;k++){
                if(b[j] == m){
                    num[k]++;
                    break;
                }
            }
        }
    }
    for(int i = 1;i <= m;i++){
        cout << num[i] << ' ';
    }
}
