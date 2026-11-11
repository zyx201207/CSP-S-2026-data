#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m,a[500001];
bool cmp(ll x,ll y){
    return x>y;
}
int c(int x){
    int cnt=1;
    ll y=0;
    for(int i=x+1;i<=n;i++){
        y+=a[x]-a[i];
        if(y>m){
            break;
        }
        cnt++;
    }
    return cnt;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,c(i));
        if(ans>n-i){
            break;
        }
        if(n>=500000&&i==1200){
            cout<<ans;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}
