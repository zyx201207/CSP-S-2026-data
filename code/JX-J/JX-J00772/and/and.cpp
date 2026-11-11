#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000000],b[100000],ans;
void dfs(int x,int f){
    b[f]=a[x];
    if(f==m){
        long long aa=b[1];
        for(int i=2;i<=m;i++){
            aa&=b[i];
        }ans=max(aa,ans);
    }for(int i=x+1;i<=n;i++){
        dfs(i,f++);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }dfs(1,1);
    cout<<ans;
}

