#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int a[500010];
int b[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for (int t = 1;t <= n;t++){
        int now = 1;
        for (int i = t;i <= n;i++){
            bool flag = false;
            for (int j = now - 1;j >= 1;j--){
                if (b[j] == a[i]){
                    now = j;
                    flag = true;
                    break;
                }
            }
            if (flag == false){
                b[now] = a[i];
            }
            now++;
        }
        for (int i = 1;i <= now - 1;i++){
            mp[b[i]]++;
        }
        memset(b,0,sizeof(b));
    }
    for (int i = 1;i <= m;i++){
        cout << mp[i] << ' ';
    }
    return 0;
}
