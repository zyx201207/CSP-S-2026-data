#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],c[200005],k=-1,sum;
void dfs(long long o,long long b){
    if(o>m+1) return;
    if(o>m){
        sum=c[1];
        for(int i=2;i<=m;i++) sum&=c[i];
        k=max(k,sum);
        return;
    }
    for(int i=b;i<=n;i++){
        c[o]=a[i];
        dfs(o+1,i+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==n){
        k=a[1];
        for(int i=2;i<=n;i++) k&=a[i];
        cout<<k;
    }else if(m==1){
        for(int i=1;i<=n;i++) k=max(k,a[i]);
        cout<<k;
    }else if(m==2){
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++){
                long long r=a[i]&&a[j];
                k=max(k,r);
            }
        cout<<k;
    }else{
        dfs(1,1);
        cout<<k;
    }
    return 0;
}
