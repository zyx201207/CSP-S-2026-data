#include<bits/stdc++.h>
using namespace std;
long long add(long long a,long long b){
    long long ans=0;
    long long t=1;
    while(a and b){
        ans+=(a%2 and b%2)*t;
        a/=2;
        b/=2;
        t*=2;
    }
    return ans;
}
long long n,m;
long long a[200005];
long long ans=0;
void dfs(long long k,long long w,long long v){
    if(k==0){
        ans=max(ans,v);
        return;
    }
    if(k==m and w==n){
        for(int i=n;i>=k;i--){
        dfs(k-1,i,a[i]);
    }
    }else{
    for(int i=w-1;i>=k;i--){
        dfs(k-1,i,add(v,a[i]));
    }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(m,n,0);
    cout<<ans;
    return 0;
}
