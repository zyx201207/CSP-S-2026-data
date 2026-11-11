#include <bits/stdc++.h>
using namespace std;
int a[500010];
int vis[500010];
int cnt[500010];
stack <int> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    for(int p = 1;p <= n;p++){
        for(int i = p;i <= n;i++){
            if(vis[a[i]] == 0){
                s.push(a[i]);
                vis[a[i]] = 1;
            }
            else{
                int k = -1;
                while(k != a[i]){
                    k = s.top();
                    s.pop();
                    vis[k] = 0;
                }
                s.push(a[i]);
                vis[a[i]] = 1;
            }
        }
        int ans = 0;
        while(!s.empty()){
            ans = s.top();
            cnt[ans]++;
            s.pop();
        }
        memset(vis,0,sizeof(vis));
    }
    for(int i = 1;i <= m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
