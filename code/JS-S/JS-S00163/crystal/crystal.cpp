#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=500005;
int n;
ll m;
ll a[N];
int ans[N];
int res;
bool cmp(ll x,ll y){
    return x>y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    ll k=0;
    int i,j=2;
    for(i=1;i<n;i++){
        for(j;j<=n;j){
            bool flag=0;
            if(k+a[i]-a[j]<=m){
                k+=a[i]-a[j];
                flag=1;
                j++;
            }
            if(!flag) break;
        }
        ans[i]=j-1-i+1;
        k-=(a[i]-a[i+1])*(j-1-i);
    }
    ans[n]=1;
    for(i=1;i<=n;i++){
        res=max(res,ans[i]);
    }
    cout<<res;
    return 0;
}
