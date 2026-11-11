#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int CCF = 2e5+5;
int n,m,maxn=-CCF;
int a[CCF]{},vis[CCF]{};
void dfs(int dep,int v){
    if(dep>m){
        maxn=max(maxn,v);
    }
    else if(dep==1){
        for(int i=1;i<=n;i++){
            vis[i]=1;
            dfs(2,a[i]);
            vis[i]=0;
        }
    }
    else{
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vis[i]=1;
                dfs(dep+1,v&a[i]);
                vis[i]=0;
            }
        }
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }
    }
    else if(m==n){
        maxn=a[1];
        for(int i=2;i<=n;i++){
            maxn&=a[i];
        }
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j){
                    maxn=max(a[i]&a[j],maxn);
                }
            }
        }
    }
    else if(m==n-1){
        for(int i=1;i<=n;i++){
            int tmp=a[1];
            if(i==1){
                tmp=a[2];
            }
            for(int j=1;j<=n;j++){
                if(i!=j){
                    tmp&=a[j];
                }
            }
            maxn=max(maxn,tmp);
        }
    }
    else{
        dfs(1,0);
    }
    cout << maxn;
    return 0;
}
//expect:25+5+5+15=50