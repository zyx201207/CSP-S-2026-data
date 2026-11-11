#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m,a[maxn],ans;
bool vis[maxn];
void dfs(int step,int km){
    if(step==m){
        if(km>ans)ans=km;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=false;
            dfs(step+1,km&a[i]);
            vis[i]=true;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<=20){
        for(int i=1;i<=n;i++){
            vis[i]=true;
            dfs(1,a[i]);
            vis[i]=false;
        }
        cout<<ans;
        return 0;
    }
    if(n<=2000){
        if(m==1){
            sort(a+1,a+n+1);
            cout<<a[n];
            return 0;
        }
        if(m==n){
            int flash=a[1];
            for(int i=2;i<=n;i++)flash&=a[i];
            cout<<flash;
            return 0;
        }
        if(m==2){
            int an=-1,s1,s2;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    an=max(an,a[i]&a[j]);
                }
            }
            cout<<an;
            return 0;
        }
    }
    else{
        sort(a+1,a+1+n);
        cout<<a[n-m+1];
    }
    return 0;
}
