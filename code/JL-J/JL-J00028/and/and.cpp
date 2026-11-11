#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll a[200010],ans;
int v[200010];
bool cmp(ll x,ll y){
    return(x>y);
}
void dfs(ll x,int st){
    if(st>=m){
        ans=max(x,ans);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!v[i]){
            v[i]=1;
            dfs(x&a[i],st+1);
            v[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        for(int i=1;i<=n;i++){
                v[i]=1;
            dfs(a[i],1);
            memset(v,0,sizeof(v));
        }
        cout<<ans<<"\n";
        return 0;
    }
    sort(a+1,a+1+n,cmp);
    if(m==2){
        for(int i=2;i<=n;i++){
            ans=max(a[i]&a[i-1],ans);
        }
        cout<<ans<<"\n";
        return 0;
    }
    ans=a[1];
    for(int i=2;i<=m;i++){
        ans&=a[i];
    }
    cout<<ans<<endl;
return 0;
}
