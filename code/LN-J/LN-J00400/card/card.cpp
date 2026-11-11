#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,m,a[N],vis[N],ans[N];
deque<int> k;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++){
        memset(vis,0,sizeof(vis));
        for(int j = i;j <= n;j++){
                //cerr << a[j] << " " << vis[a[j]]<< endl;
            if(vis[a[j]] == 1)while(k.front() != a[j]) k.pop_front();
            else {
                vis[a[j]] = 1;
                k.push_front(a[j]);
            }
        }
        while(!k.empty()) {
            //cerr << vis[k.front()] << endl;
            if(vis[k.front()] == 1){
                vis[k.front()] = 0;
                ans[k.front()]++;
            }
            //cerr << "1" << endl;
            k.pop_front();
            //cerr << "---" << endl;
        }
    }
    for(int i = 1;i <= m;i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
//I want CSP-S 200+  thank the best CCF
