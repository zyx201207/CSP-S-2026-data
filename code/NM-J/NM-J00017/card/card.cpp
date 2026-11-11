#include <bits/stdc++.h>
using namespace std;
int n, m, ji, shu[500010];
stack <int>q;
bool a[300010];
int ans[300010];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> shu[i];
    }
    for(int i = 1;i <= n;i++){
        while(!q.empty()){
            q.pop();
        }
        memset(a, 0, sizeof(a));
        for(int j = i;j <= n;j++){
            if(a[shu[j]] == 0){
                a[shu[j]] = 1;
            }else{
                while(q.top() != shu[j]){
                    a[q.top()] = 0;
                    q.pop();
                }
                q.pop();
            }
            q.push(shu[j]);
        }
        for(int j = 1;j <= m;j++){
            if(a[j] == 1){
                ans[j]++;
            }
        }
    }
    for(int i = 1;i <= m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
