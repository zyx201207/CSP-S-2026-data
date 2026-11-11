#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
long long cnt=0;
long long n,m;
long long fun(long long maxn){
    for(long long i=1;i<=n;i++){
        if(b[i]!=-1){
            maxn=max(maxn,(maxn&b[i]));
            b[i]=-1;
        }
    }
    cnt++;
    if(cnt==m){
        return maxn;
    }
    else{
        fun(maxn);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    long long maxn=0;
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            b[j]=a[j];
        }
        maxn=max(maxn,fun(b[i]));
        b[i]=-1;
    }
    cout<<maxn;
    return 0;
}
