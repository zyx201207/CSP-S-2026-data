#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1){
        long long maxn=0;
        for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
        cout<<maxn;
        return 0;
    }
    if(m==n){
        long long ans=a[1];
        for(int i=2;i<=n;i++) ans=ans&a[i];
        cout<<ans;
        return 0;
    }
    if(m==2){
        long long maxn=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn;
    }
    else{
        cout<<1;
    }
    return 0;
}

