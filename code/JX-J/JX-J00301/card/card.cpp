#include <bits/stdc++.h>
using namespace std;
int a[500005];
int ans[300005];
int n, m;
int main(){
	//freopen("card.in", "r", stdin);
	//freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int sz[500005];
    int xb = 0;
    for(int i = 1; i <= n; i++){
        memset(sz, 0, sizeof(0));
        for(int j = i; j <= n; j++){
            xb++;
            sz[xb] = a[j];
            for(int k = 1; k <= xb; k++){
                if(sz[k] == a[j]){
                    for(int p = k; p <= xb; p++){
                        sz[p] = 0;
                        xb = k;
                    }
                }
            }
            
        }
        for(int j = 1; j <= xb; j++){
            ans[sz[j]]++;
        }
    }
    for(int i = 1; i <= m; i++){
        cout << ans[i] << " ";
    }
    return 0;
}

