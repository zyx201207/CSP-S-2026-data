#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],dans=0;
bool use[200005];
void dfs(int id,ll t,ll now){
    if(id>n){
        if(!t)dans=max(dans,now);
        return;
    }
    if(t){
        use[id]=1;
        dfs(id+1,t-1,now&a[id]);//xuan3
        use[id]=0;
    }
    dfs(id+1,t,now);//bu4xuan3
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n];
        return 0;
    }else if(m==n){
        ll ans=a[1];
        for(int i=2;i<=n;i++)ans&=a[i];
        cout<<ans;
        return 0;
    }else if(m==2){
        ll ans=0;
        for(int i=1;i<n;i++)
            for(int j=2;j<=n;j++)
                ans=max(ans,a[i]&a[j]);
        cout<<ans;
        return 0;
    }else{//qiu2qiu2bao4li4de2dian3fen1...
        dfs(1,m,2147483647);
        cout<<dans;
        return 0;
    }
    return 0;
}
