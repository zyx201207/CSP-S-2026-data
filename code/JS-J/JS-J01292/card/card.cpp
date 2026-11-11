#include<bits/stdc++.h>
using namespace std;

int ans[300001];
int a[500001];
int n,m;
vector<int> f[300001];
void dfs(int dep){
    if(dep>n) return ;
    for(int i=0;i<f[a[dep]].size();i++)
    {
        if(f[a[dep]][i]==dep)
        {
            if(f[a[dep]].size()-i) ans[a[dep]]++;
            break;
        }
    }
    dfs(f[a[dep]][f[a[dep]].size()-1]+1);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[a[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        dfs(i);
    }
    for(int i=1;i<m;i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<ans[m];
    return 0;
}
