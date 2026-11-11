#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,m,a[N],ans1=0;
void dfs(int x,int i,ll sum){
    if(x==m){
        if(sum!=INT_MAX) ans1=max(ans1,sum);
        return ;
    }
    if(i>n) return ;
    dfs(x+1,i+1,sum&a[i]);
    dfs(x,i+1,sum);
    return ;
}
bool cmp(ll x,ll y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    if(n<=20){
        dfs(0,1,INT_MAX);
        cout<<ans1<<'\n';
        return 0;
    }else if(m==1){
        cout<<a[1]<<'\n';
        return 0;
    }else if(m==n){
        ll ans=INT_MAX;
        for(int i=1;i<=n;i++) ans&=a[i];
        cout<<ans<<'\n';
        return 0;
    }else if(m==2){
        ll ans=-1;
        for(int j=2;j<=n;j++){
            for(int i=1;i<=j-1;i++){
                if((a[i]&a[j])==a[j]){
                    cout<<a[j]<<'\n';
                    return 0;
                }
                ans=max(ans,(ll)(a[i]&a[j]));
            }
        }
        cout<<ans<<'\n';
        return 0;
    }else{
        ll ans=INT_MAX;
        for(int i=1;i<=m;i++) ans&=a[i];
        cout<<ans<<'\n';
        return 0;
    }
    return 0;
}
