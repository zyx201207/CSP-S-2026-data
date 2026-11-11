#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],mc[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i =1;i <= n;i++)cin >> a[i];
    for (int i = 1;i <= n;i++){
        int x[500005] = {},cnt = i;
        for (int k = i;k <= n;k++){
            x[cnt] = a[k];
            for (int j = i;j <= cnt;j++){
                if (x[j] == x[cnt]){
                    cnt = j;
                    break;
                }
            }
        }
        for (int j = i;j <= cnt;j++)mc[x[j]]++;
    }
    for (int i = 1;i <= m;i++)cout << mc[i] << " ";
    return 0;
}
