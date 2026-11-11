#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,d,a[2000005],ans,mn=2e9,cnt=0;
void dfs1(int s,int t,int d){
    if(s>=t){
        mn=min(mn,d);
        return;
    }
    int k=0;
    for(int i=s+1;i<=t;i++){
        k+=a[i];
        if(k>d) break;
        dfs1(i,t,d+1);
    }
}
void dfs2(int ss,int tt,int dd){
    if(ss>=tt){
        if(dd==mn) cnt++;
        return;
    }
    int k=0;
    for(int i=ss+1;i<=tt;i++){
        k+=a[i];
        if(k>d) break;
        dfs2(i,tt,dd+1);
    }
}
bool check(int x,int y){
    mn=2e9;
    dfs1(x,y,1);
    cnt=0;
    dfs2(x,y,1);
    if(cnt==2) return true;
    else return false;
}
signed main(){
    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(check(i,j)) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
