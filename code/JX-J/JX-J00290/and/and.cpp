#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200009],tot,x;
long long max(long long zho,long long zht){
    if(zho>zht)
        return zho;
    return zht;
}
void dfs(long long wz,long long tott,long long js){
    if(wz==n&&js!=m)
        return ;
    if(js==m){
        tot=max(tot,tott);
    }
    for(long long i=wz+1;i<=n;i++){
        dfs(i,tott&a[i],js+1);
    }
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        long long dd=0;
        for(int i=1;i<=n;i++){
            dd=max(dd,a[i]);
        }
        cout<<dd;
        return 0;
    }
    if(m==n){
        long long dd=a[1];
        for(int i=2;i<=n;i++){
            dd=dd&a[i];
        }
        cout<<dd;
        return 0;
    }
    for(long long i=1;i<=n;i++){
        dfs(i,a[i],1);
    }
    cout<<tot;
}
