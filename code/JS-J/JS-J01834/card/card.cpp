#include <bits/stdc++.h>
using namespace std;
queue<int> q[500005];
int a[300005];
int n, m;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        q.push(i);
    }
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        int p = -1;
        int z = q.size();
        for(int j = 0;j < z;j++){
            if(q[i] == a[i]) p = j;
        }
        if(p == -1) q.push(a[i]);
        else{
            for(int j = 0;j < z;j++){
                if(j < p){
                    q.push(q.[j]);
                }
                q.pop();
            }
            q.push(a[i]);
        }
        for(int j = 0;j < q.size();j++){
            if(q[j] == a[i]) cnt++;
        }
    }
    cout << cnt;
    return 0;
}
