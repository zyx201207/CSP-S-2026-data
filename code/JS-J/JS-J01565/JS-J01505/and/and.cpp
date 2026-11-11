#include <bits/stdc++.h>

using namespace std;
int a[200200],v[200200],xx=-1,n,m,l,ans=-1,y=INT_MAX;
void dfs(int w,int i,int x){
    if(i==m){
        ans=max(x,ans);
        return;
    }
    for(int j=w;j<=n;j++){
        if(n-j<m-i) return;

        if(v[j]!=1){
            v[j]++;

            int ww=x&a[j];
            int ii=i+1,jj=j+1;
            dfs(jj,ii,ww);
            v[j]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        xx=max(a[i],xx);
        if(i==1) l=a[i];
        else l=l&a[i];
    }
    if(m==1){
        cout<<xx;
    }
    else if(m==n){
        cout<<l;
    }else {
        dfs(1,0,y);
        cout<<ans;
    }

    return 0;
}
