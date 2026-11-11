#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+8;
const int M = 3e5+8;

int n,m,a[N],buc[M],ans[M];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        buc[a[i]]++;
    }
    for(int i = 1;i <= n;i++){
        buc[a[i-1]]--;
        for(int j = i;j <= n;j++){
            if(buc[a[j]] > 1){
                for(int k = n;k >= j+1;k--){
                    if(a[k] == a[j]){
                        j = k;
                        break;
                    }
                }
            }
            ans[a[j]]++;
        }
    }
    for(int i = 1;i <= m;i++){
        cout << ans[i] << " ";
    }
}
