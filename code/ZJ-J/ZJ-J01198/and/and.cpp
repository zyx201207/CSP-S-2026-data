#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
const int N=2e5+7;
int n,m;
int a[N];
bool vis[N];
bool ck1(int a,int b){
    int res=1;
    for(int i=a;i>=a-b+1;i--){
        res*=i;
        if(res>1e9)
            return 0;
    }
    return 1;
}
int dfs(int x,int res){
    if(x>m)
        return res;
    int mx=0;
    for(int i=1;i<=n;i++)
        if(!vis[i]){
            vis[i]=1;
            mx=max(mx,dfs(x+1,res&a[i]));
            vis[i]=0;
        }
    return mx;
}
int dfs(int x){
    if(x>n-m){
        int res=INT_MAX;
        for(int i=1;i<=n;i++)
            if(!vis[i])
                res&=a[i];
        return res;
    }
    int mx=0;
    for(int i=1;i<=n;i++)
        if(!vis[i]){
            vis[i]=1;
            mx=max(mx,dfs(x+1));
            vis[i]=0;
        }
    return mx;
}
bool check(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=31;j++)
            if(a[i]!=1<<j-1)return 0;
    return 1;
}
void mian(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<=20){
        if(m<=n/2)
            cout<<dfs(1,INT_MAX);
        else 
            cout<<dfs(1);
    }
    else if(n<=2000){
        if(m==1){
            sort(a+1,a+n+1,greater<int>());
            cout<<a[1];
        }
        else if(m==n){
            int res=a[1];
            for(int i=1;i<=n;i++)
                res&=a[i];
            cout<<res;
        }
        else if(ck1(n,m))
            cout<<dfs(1,INT_MAX);
        else
            cout<<dfs(1);
    }
    else{
        if(check())
            cout<<a[1];
        else if(ck1(n,n-m))
            cout<<dfs(1);
        else
            cout<<dfs(1,INT_MAX);
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int _77231=1;
    // cin>>_77231;
    while(_77231--)mian();
}