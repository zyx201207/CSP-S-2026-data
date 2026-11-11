#include<bits/stdc++.h>
using namespace std;
int m,n,a[10000],sum[1000],u=0,maxn;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-m;i++){
        if(a[i]==a[i+1]){
            sum[u]=a[i];
            u++;
        }
    }
    for(int i=1;i<=u;i++){
        maxn=max(sum[u],sum[u-1]);
    }
    cout<<maxn;
    return 0;
}
