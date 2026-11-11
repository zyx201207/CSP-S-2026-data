#include <bits/stdc++.h>
using namespace std;
int n , m , a[500005] , box[300005] , b[500005] , ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        int x = 1;
        int box[300005] = {};
        for(int j = i;j <= n;j++){
            if(box[a[j]] == 0){
                box[a[j]]++;
                b[x] = a[j];
                x++;
            }

            else{
                int box[300005];
                for(int k = 1;k <= x;k++){
                    b[k] = 0;
                }
                x = 1;
                b[x] = a[j];
                box[a[j]]++;
                x++;
            }
        }
        for(int j = 1;j <= m;j++){
            for(int k = 1;k < x;k++){
                if(b[k] == j){
                    ans[j]++;
                }
            }
        }
    }
    for(int i = 1;i <= m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
