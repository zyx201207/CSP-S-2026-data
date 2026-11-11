#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool v[200005];
long long n,m,ans=0;
void dp(long long i,long long c){
    if(c==m){
        ans=max(ans,i);
        return;
    }
    if(i<ans) return;
    for(long long j=1;j<=n;j++){
        if(v[j]==0){
            v[j]=1;
            dp(i&a[j],c+1);
            v[j]=0;
        }
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>> n >> m;
    for(long long i=1;i<=n;i++) cin>> a[i];
    if(m==n){
        long long k=a[1];
        for(long long i=2;i<=n;i++){
            k=(k&a[i]);
        }
        cout<< k;
        return 0;
    }
    for(long long i=1;i<=n;i++){
        v[i]=1;
        dp(a[i],1);
    }
    cout<< ans;
    return 0;
}
