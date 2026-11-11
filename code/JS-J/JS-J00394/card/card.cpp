#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 50;
const int M = 3e5 + 10;
int a[N],ans[M],vis[M],n,m;
stack<int> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++){
        for (int j = i;j <= n;j++){
            if (!vis[a[j]]){
                s.push(a[j]);
                vis[a[j]] = true;
            }else{
                while(!s.empty()){
                    int num = s.top();
                    if (num == a[j]){
                        s.pop();
                        break;
                    }
                    s.pop();
                    vis[num] = false;
                }
                s.push(a[j]);
                vis[a[j]] = true;
            }
        }
        while(!s.empty()){
            int x = s.top();
            ans[x]++;
            s.pop();
        }
        memset(vis,0,sizeof(vis));
    }
    for (int i = 1;i <= m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
