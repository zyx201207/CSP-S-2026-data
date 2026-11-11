#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m, cnt=0;
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    for(int j=1; j<=m; j++){
        int p = 0;
        for(int i=1; i<=n; i++){
            if(a[i] = j){
                p++;
                if(p ==2){
                    n-=i;
                    cnt++;
                    p=0;
                    break;
                }
            }
        }
        cout << cnt << " ";
        cnt=0;
    }
    return 0;
}
