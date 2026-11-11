#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],tong[300005],ton[300005];
bool qfind (queue <int> q,int n){
    bool flag = 0;
    while (!q.empty()){
        if (q.front() == n) flag = 1;
        q.pop();
    }
    return flag;
}
int main (){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    queue <int> q;
    cin >> n >> m;
    memset(tong,0,sizeof(tong));
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++){
        memset(ton,0,sizeof(ton));
        while (!q.empty()) q.pop();
        for (int j = i;j <= n;j++){
            if (j != 1){
                if (qfind(q,a[j])){
                    while (!q.empty()){
                        ton[q.front()] = 0;
                        q.pop();
                    }
                }
            }
            q.push(a[j]);
            ton[a[j]]++;
        }
        for (int j = 1;j <= m;j++){
            if (ton[j]){
                tong[j]++;
            }
        }
    }
    for (int i = 1;i <= m;i++){
        cout << tong[i] << " ";
    }
    return 0;
}
