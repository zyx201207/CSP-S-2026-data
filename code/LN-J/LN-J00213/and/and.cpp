#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[200005],n,m,a[200005];
int dfs(int pos,int nu,bool c[25]){
    if(pos==n+1 && nu!=m)return -1e9;
    if(pos==n+1 && nu==m){
        int t=-1e9;
        for(int i=1;i<=n;i++){
            if(c[i] && t==-1e9){
                t=a[i];
            }
            else if(c[i])t=t&a[i];
        }
        return t;
    }
    if(nu==m)return dfs(pos+1,nu,c);
    int a,b;
    a=dfs(pos+1,nu,c);
    c[pos]=1;
    b=dfs(pos+1,nu+1,c);
    return max(a,b);
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int ma=-1e9;
    int ma2=-1e9;
    for(int i=1;i<=n;i++)cin>>a[i],ma=max(ma,a[i]);
    bool c[25];
    memset(c,0,sizeof(c));
    //cout<<m;
    if(m==1)cout<<ma;
    else if(m==n){
        int t=a[1];
        for(int i=2;i<=n;i++)t=t&a[i];
        cout<<t;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ma2=max(ma2,a[i]&a[j]);
            }
        }
        cout<<ma2;
    }

    else if(n<=20)cout<<dfs(1,0,c);
    else {
        sort(a+1,a+n+1);
        cout<<a[m];
    }
}
