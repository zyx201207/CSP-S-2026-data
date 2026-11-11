#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2e5+10;
int a[MAXN],n,m,maxx;
bool vis[MAXN];
int ans[MAXN];
void dfs(int dep,int last){
    if(dep==m+1){
        int sum=ans[1];
        for(int i=2;i<=m;i++){
            sum=(sum&ans[i]);
        }
        maxx=max(maxx,sum);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]&&i>last){
            vis[i]=true;
            ans[dep]=a[i];
            dfs(dep+1,i);
            vis[i]=false;
            ans[dep]=0;
        }
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=20||m==n-1){
        dfs(1,0);
        cout<<maxx;
        return 0;
    }
    if(m==1){
        for(int i=1;i<=n;i++) maxx=max(a[i],maxx);
        cout<<maxx;
        return 0;
    }
    if(m==n){
        int sum=a[1];
        for(int i=2;i<=n;i++){
            sum=(sum&a[i]);
        }
        cout<<sum;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxx=max(maxx,(a[i]&a[j]));
            }
        }
        cout<<maxx;
        return 0;
    }
    int t=0;
    for(int i=1;i<=n;i++) t=max(t,a[i]);
    if(t<=4){
        cout<<t;
        return 0;
    }
    sort(a+1,a+1+n,greater<int>());
    cout<<a[m];
    return 0;
}
