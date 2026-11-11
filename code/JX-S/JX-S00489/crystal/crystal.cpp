#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005];
void f(int s,int e,int l,long long k){
    ans=max(ans,l);
    if(e==n) return;
    if(k+(a[e+1]-a[e])*l<=m){
        f(s,e+1,l+1,k+(a[e+1]-a[e])*l);
    }else{
        f(s+1,e,l-1,k-(a[e]-a[s]));
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    f(1,1,1,0);
    cout<<ans<<endl;
    return 0;
}
