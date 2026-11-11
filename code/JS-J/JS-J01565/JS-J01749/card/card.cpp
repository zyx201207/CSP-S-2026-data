#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int c[500005];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        int pos = 1;
        for(int j = i; j <= n; j++){
            for(int k = 1; k < pos; k++){
                if(b[k] == a[j]){
                    pos = k;
                    break;
                }
            }
            b[pos] = a[j];
            pos++;
        }
        for(int j = 1; j < pos; j++){
            c[b[j]]++;
        }
        cout << endl;
    }
    for(int i = 1; i <= m; i++){
        cout << c[i] << " ";
    }
    cout << endl;
    return 0;
}
