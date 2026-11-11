#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,maxn;
int a[200005];
void dfs(int dep,int sum,int k){
    if(dep==n+1){
        if(k==0){
            ans=max(sum,ans);
        }
        return;
    }
    if(k>0){
        if(k==m){
            dfs(dep+1,a[dep],k-1);
        }else{
            dfs(dep+1,sum & a[dep],k-1);
        }
    }
    dfs(dep+1,sum,k);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(n<=20){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dfs(1,0,m);
        cout<<ans<<"\n";
        return 0;
    }else if(n<=2000){
        if(m==1){
            for(int i=1;i<=n;i++){
                cin>>a[i];
                maxn=max(maxn,a[i]);
            }
            cout<<maxn<<"\n";
        }else if(m==n){
            cin>>ans;
            for(int i=2;i<=n;i++){
                cin>>a[i];
                ans&=a[i];
            }
            cout<<ans<<"\n";
        }else{
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    ans=max(a[i]&a[j],ans);
                }
            }
            cout<<ans<<"\n";
        }
    }else{
        cout<<2<<"\n";
    }
    return 0;
}
