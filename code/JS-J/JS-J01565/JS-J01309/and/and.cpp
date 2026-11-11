#include<bits/stdc++.h>
using namespace std;

long long n,m,a[200005],mx=0,s=0;
void dfs1(long long i,long long p,long long t){
    if(i>=m){
        mx=max(mx,t);
        return;
    }
    for(int j=p+1;j<=n-m+i+1;j++){
        dfs1(i+1,j,t&a[j]);
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n-m+1;i++)dfs1(1,i,a[i]);
    cout<<mx;
    return 0;
}
