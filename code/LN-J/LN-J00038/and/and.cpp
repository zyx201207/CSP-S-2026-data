#include <bits/stdc++.h>
using namespace std;
int m,n,ind;
long long a[200005],ans;
bool vis[200005];
long long q[200005];
bool cmp(long long a,long long b){
    return a>b;
}
void dfs(int dep){
    if(dep>m){
            long long t=q[1];
            for(int i=1;i<=m;i++)t&=q[i];
            ans=max(ans,t);
            return;
        }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=true;
            q[dep]=a[i];
            dfs(dep+1);
            vis[i]=false;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    bool isA=true,isB=true;
    long long ma=0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(n<=2000){
        dfs(1);
        cout << ans;
    }else{
        sort(a+1,a+n+1,cmp);
        ans=a[1];
        for(int i=1;i<=m;i++)ans&=a[i];
        cout << ans;
    }
    return 0;
}
