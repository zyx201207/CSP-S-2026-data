#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,mas=0,a[200005],mass=0;
int vis[200005]={0};
void dfs(long long x,long long y){
    if(x==m){
        //cout<<":"<<y<<endl;
        mass=max(mass,y);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            //cout<<a[i]<<" ";
            dfs(x+1,(y&a[i]));
            vis[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mas=max(a[i],mas);
    }
    ans=a[1];
    if(m==1){
        cout<<mas;
        return 0;
    }
    if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans=(ans&a[i]);
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        vis[i]=1;
        dfs(1,a[i]);
        vis[i]=0;
    }
    cout<<mass;
    return 0;
}
