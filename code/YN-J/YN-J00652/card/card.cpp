#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e5+5;
int n,m,a[N],ans[N];

int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        stack<int> stk;
        vector<bool> vis(m+1,0);
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                while(!stk.empty()&&stk.top()!=a[j]){
                    vis[stk.top()]=0;
                    stk.pop();
                }
                if(!stk.empty()&&stk.top()==a[j]){
                    stk.pop();
                }
                vis[a[j]]=0;
            }
            stk.push(a[j]);
            vis[a[j]]=1;
        }
        while(!stk.empty()){
            ans[stk.top()]++;
            stk.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
