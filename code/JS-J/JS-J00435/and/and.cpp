#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;

ll n,m,a[200005],v[200005];
bool cmp(ll a,ll b){return a>b;}
ll k=0,ans=0;

void dfs(int step){
    if(step>m){
        ans=max(ans,k);
        return;
    }
    for(int i=v[step-1]+1;i<=n;i++){
        ll g=k;
        if(step==1)k=a[i];else k=k&a[i];
        v[step]=i;
        dfs(step+1);
        v[step]=0;
        k=g;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n,cmp);
    dfs(1);
    cout<<ans;
    return 0;
}
