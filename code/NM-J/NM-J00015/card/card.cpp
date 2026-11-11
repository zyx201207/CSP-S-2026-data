#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
using namespace std;
const int maxn = 5e5+10;
const int maxm = 3e5+10;
int n,m;
int a[maxn],ans[maxm],st[maxn],vis[maxm];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        memset(st,0,sizeof(st));
        memset(vis,0,sizeof(vis));
        //stack<int> s;
        int top = 1;
        for (int j=i;j<=n;j++){
            if (!vis[a[j]]){
                vis[a[j]] = 1;
                st[top++] = a[j];
                //top++;
            }
            else {
                top--;
                while (st[top] != a[j]){
                    vis[st[top]] = 0;
                    top--;
                }
                top++;
            }
        }
        for (int k=1;k<=m;k++){
             if (vis[k]){
                ans[k] ++;
            }
        }
        /*while (!s.empty()){
            ans[s.top()]++;
            s.pop();
        }*/
    }
    for (int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
