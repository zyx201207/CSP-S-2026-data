#include<bits/stdc++.h>
using namespace std;
long long n,m,mx=INT_MIN,ans=INT_MIN;
long long f[200005];
void dg(long long x,long long s,long long k){
    if(x==m){
        ans=max(ans,s);
        return;
    }
    if(k==n+1){
        return;
    }
    dg(x,s,k+1);
    if(x==0){
        dg(x+1,f[k],k+1);
    }
    else{
        dg(x+1,int(s&f[k]),k+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>f[i];
        mx=max(mx,f[i]);
    }
    if(m==1){
        cout<<mx;
        return 0;
    }
    if(m==n){
        ans=f[1];
        for(long long i=2;i<=n;i++){
            ans=ans&f[i];
        }
        cout<<ans;
        return 0;
    }
    dg(0,0,1);
    cout<<ans;
    return 0;
}
