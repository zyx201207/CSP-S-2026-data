#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int ans;
int mx;
int a[200005];
bool vis[200005];
void dfs(int step,int sum){
    if(step==m) ans=max(ans,sum);
    for(int i=1;i<=n;i++){
        if(vis[a[i]]) continue;
        else{
            vis[a[i]]=1;
            dfs(step+1,sum & a[i]);
            vis[a[i]]=0;
        }
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
    if(n<=20){
        dfs(0,2e20-1);
        cout<<ans;
    }
    else{
        if(m==1) cout<<mx;
        else{
            if(m==n){
                int print=a[1];
                for(int i=2;i<=n;i++){
                    print &= a[i];
                }
                cout<<print;
            }
            else if(m==2){
                int print=0;
                for(int i=1;i<=n;i++){
                    for(int j=i+1;j<=n;j++){
                        print=max(a[i] & a[j],print);
                    }
                }
                cout<<print;
            }
            else cout<<mx;
        }
    }
    return 0;
}
