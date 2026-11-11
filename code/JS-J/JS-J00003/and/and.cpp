#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,m;
ll a[N];
ll mx=(1<<30)-1;
int st[N];
int flag=0;
void dfs(int x,ll ans){
    if(x==m){
        mx=max(mx,ans);
        flag=1;
        return ;
    }
    if(flag&&ans<mx) return;
    for(int i=n;i>=1;i--){
        if(st[i]) continue;
        st[i]=1;
        dfs(x+1,ans&a[i]);
        st[i]=0;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx&=a[i];
    }
    sort(a+1,a+1+n);
    if(mx==a[n-m+1]){
        cout<<mx;
        return 0;
    }
    if(n==m){
        int an=a[1];
        for(int i=2;i<=n;i++){
            an&=a[i];
        }
        cout<<an;
        return 0;
    }
    else if(n==m+1){
        int anss=a[2];
        for(int i=3;i<=n;i++){
            anss&=a[i];
        }
        cout<<anss;
    }
    dfs(0,(1<<30)-1);
    cout<<mx;
    return 0;
}
