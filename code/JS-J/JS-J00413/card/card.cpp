#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5005;
int n,m;
int a[maxn];
int ans[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        cout<<n;
        return 0;
    }
    stack<int> q;
    bool f[maxn];
    for(int i=1;i<=n;i++){
        fill(f,f+n+1,false);
        for(int j=i;j<=n;j++){
            if(f[a[j]]){
                int k=j-1;
                while(a[k]!=a[j]&&!q.empty()){
                    q.pop();
                    k--;
                }
                continue;
            }
            q.push(a[j]);
            f[a[j]]=true;
        }
        while(!q.empty()){
            int p=q.top();
            ans[p]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
