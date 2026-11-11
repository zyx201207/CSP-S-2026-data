#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+7;
int n,m;
int a[maxn];

int ans=-1;

bool vis[maxn];
int t[maxn];
void dfs(int u){
    if(u==m){
        int sum_and=t[1];
        for(int i=2;i<=u;i++) sum_and&=t[i];
        ans=max(ans,sum_and);
        return;
    }

    for(int i=1;i<=n;i++)
        if(!vis[i]){
            vis[i]=1;
            t[u+1]=a[i];
            dfs(u+1);
            vis[i]=0;
        }
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(n==m) ans&=a[i];
    }
    if(n==m){
        cout<<ans<<"\n";
        return 0;
    }
    if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n]<<"\n";
        return 0;
    }

    dfs(0);

    cout<<ans<<"\n";

    return 0;
}
