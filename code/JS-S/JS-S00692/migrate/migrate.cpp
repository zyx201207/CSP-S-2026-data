#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll d,a[2000005],cnt[15];
int n;
void dfs(int u,int v,int b){
    if(u==v){
        cnt[b]++;
        return;
    }
    for(int i=u+1;i<=v;i++){
        if(a[i]-a[u]>d)
            break;
        dfs(i,v,b+1);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        int ans=0;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(n<=9){
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    memset(cnt,0,sizeof(cnt));
                    dfs(i,j,0);
                    for(int k=1;k<=15;k++){
                        if(cnt[k]!=0){
                            if(cnt[k]==2)
                                ans++;
                            break;
                        }
                    }
                }     
            }
            cout<<ans<<'\n';
            continue;
        }
        ll t=a[2]-a[1];
        for(ll x=1;x<=n+1;x++){
            if(2*d-x*t>=0&&2*d-x*t<t){
                if(x%2==0)
                    x--;
                ans=n-x;
                break;
            }
        }
        if(ans==n-1)
            ans=0;
        if(d<t)
            ans=0;
        cout<<ans<<'\n';
    }
    return 0;
}