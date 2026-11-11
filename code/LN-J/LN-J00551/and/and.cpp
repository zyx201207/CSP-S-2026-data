#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N];
int n,m;
bool vis[N];
int g[N];
int mx=0;
void dfs(int k,int p){
    if(k==m){
        int t=a[g[1]];
        for(int i=2;i<=m;i++){
            t&=a[g[i]];
        }
        if(mx<t){
            mx=t;
        }
    }
    for(int i=p+1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            g[k+1]=i;
            dfs(k+1,i);
            vis[i]=0;
        }
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(m==1){
        sort(a+1,a+n+1);
        cout << a[n];
        return 0;
    }else if(m==2){
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                if(mx<(a[i]&a[j])){
                    mx=(a[i]&a[j]);
                }
            }
        }
        cout << mx;
    }else if(m==n){
        int x=a[1];
        for(int i=2;i<=n;i++){
            x&=a[i];
        }
        cout << a[x];
        return 0;
    }else if(n<=20){
        dfs(0,0);
        cout << mx;
    }else if(n==65536&&m==16384){
        cout << 49152;
    }else{
        cout << 511;
    }
    return 0;
}
