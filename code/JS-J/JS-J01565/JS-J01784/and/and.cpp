#include<bits/stdc++.h>
using namespace std;
int n,m,maxx=0,k=4294967295,maxi=0;
int a[200005];
bool vis[200005];
bool tf=true;
inline void dfs(int step,int sum){
    if(step==m){
        maxx=max(maxx,sum);
        if(maxx==maxi){
            cout<<maxx;
            exit(0);
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=true;
            dfs(step+1,sum&a[i]);
            vis[i]=false;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //check this before you submit!

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxi=max(maxi,a[i]);
        k=k&a[i];
        float t=log(a[i]);
        if(t-int(t)!=0){
            tf=false;
        }
    }
    if(m==1){
        cout<<maxi;
        return 0;
    }
    if(m==n){
        cout<<k;
        return 0;
    }
    if(tf){
        sort(a+1,a+1+n);
        cout<<a[n-m];
        return 0;
    }
    maxx=0;
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxx=max(maxx,a[i]&a[j]);
            }
        }
        cout<<maxx;
        return 0;
    }
    maxx=0;
    for(int i=1;i<=n;i++){
        vis[i]=true;
        dfs(1,a[i]);
        vis[i]=false;
    }
    cout<<maxx;
    return 0;
}
