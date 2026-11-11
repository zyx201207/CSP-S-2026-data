#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],an=-1;
void dfs(int cnt,int ad,int idx){
    if(cnt==m){
        an=max(an,ad);
        return;
    }
    for(int i=idx+1;i<=n;i++){
        int t=ad&a[i];
        dfs(cnt+1,t,i);
    }
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==m){
        int s=1;
        for(int i=1;i<=n;i++){
            s=s&a[i];
        }
        cout<<s<<'\n';
        return 0;
    }
    if(m==1){
        int maxa=-1;
        for(int i=1;i<=n;i++){
            maxa=max(maxa,a[i]);
        }
        cout<<maxa<<'\n';
        return 0;
    }
    if(m==2){
        int ans=-1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                int tmp=a[i]&a[j];
                ans=max(ans,tmp);
            }
        }
        cout<<ans<<'\n';
        return 0;
    }
    if(m==n-1){
        int ans=-1;
        for(int i=1;i<=n;i++){
            int tmp=1;
            for(int j=1;j<=n;j++){
                if(j==i) continue;
                tmp=tmp&a[j];
            }
            ans=max(ans,tmp);
        }
        cout<<ans<<'\n';
        return 0;
    }
    dfs(1,a[1],1);
    cout<<an<<'\n';
    return 0;
}
