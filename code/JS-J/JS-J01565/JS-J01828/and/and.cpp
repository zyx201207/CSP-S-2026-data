#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m;
int a[N];
int f[35];
string s[N];
int ans=0;
int vis[N];
void init(void){
    int fact=1;
    for(int i=0;i<=30;++i){
        f[i]=fact;
        fact*=2;
    }
    return;
}
void dfs(int dep,int sum){
    if(dep>m){
        ans=max(ans,sum);
        return;
    }
    if(sum==0) return;
    int pos=-1;
    for(int i=1;i<=n;++i) if(!vis[i]&&sum&a[i]==sum){
        pos=1;
        break;
    }
    for(int i=1;i<=n;++i) if(!vis[i]){
        vis[i]=1;
        dfs(dep+1,sum&a[i]);
//        cout<<sum<<'\n';
        vis[i]=0;
    }
    if(pos!=-1) dfs(dep+1,sum);
    return;
}
void dfs2(int dep,int sum){
    if(dep>n-m){
        int res=INT_MAX;
        for(int i=1;i<=n;++i) if(!vis[i]) res&=a[i];
        ans=max(ans,res);
        return;
    }
    if(sum==0) return;
    int pos=-1;
    for(int i=1;i<=n;++i) if(!vis[i]&&sum&a[i]==sum){
        pos=1;
        break;
    }
    for(int i=1;i<=n;++i) if(!vis[i]){
        vis[i]=1;
        dfs(dep+1,sum&a[i]);
//        cout<<sum<<'\n';
        vis[i]=0;
    }
    if(pos!=-1) dfs(dep+1,sum);
    return;
}
signed main(void){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    int fl=1;
    for(int i=1;i<=n;++i){
        int x;
        cin>>x;
        a[i]=x;
        for(int j=0;j<=30;++j) if(!fl||a[i]!=f[j]){
            fl=0;
            break;
        }
    }
    if(fl){
        sort(a+1,a+n+1,greater<int>());
        cout<<a[m];
    }
    else if(m!=1&&m!=n&&pow(n,m)<=1e8){
        dfs(1,INT_MAX);
        cout<<ans;
    }
    else if(pow(n,n-m)<=1e8){
        dfs2(1,INT_MAX);
        cout<<ans;
    }
    else if(m==1){
        sort(a+1,a+n+1,greater<int>());
        cout<<a[1];
    }
    else if(m==n){
        ans=INT_MAX;
        for(int i=1;i<=n;++i) ans&=a[i];
        cout<<ans;
    }
    else if(2*m<n){
        dfs(1,INT_MAX);
        cout<<ans;
    }
    else{
        dfs2(1,INT_MAX);
        cout<<ans;
    }
    return 0;
}
