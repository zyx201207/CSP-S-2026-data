#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
bool vis[200005];
int n,m;
void dfs(int &ans,int di,int cnt){
    if(di==m){
        ans=max(ans,cnt);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(ans,di+1,cnt&a[i]);
            vis[i]=0;
        }
    }
    return ;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    bool f=1,d=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        bool op=0;
        for(int j=0;j<=30;j++){
            if(a[i]==(1<<j)-1){
                op=1;
                break;
            }
        }
        if(!op) f=0;
        if(a[i]>=4) d=0;
    }
    if(m==1){
        int maxx=-INT_MAX;
        for(int i=1;i<=n;i++){
            maxx=max(maxx,a[i]);
        }
        cout<<maxx;
        return 0;
    }
    else if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    else if(m==2){
        int ans=-INT_MAX;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    else if(f){
        sort(a+1,a+n+1,greater<>());
        cout<<a[m];
        return 0;
    }
    else if(d&&n>2000){
        sort(a+1,a+n+1,greater<>());
        if(a[m]==3) cout<<3;
        else if(a[m]==2) cout<<2;
        else if(a[m]==1){
            int cnt1=0,cnt3=0;
            for(int i=1;i<=n;i++){
                if(a[i]==1) cnt1++;
                else if(a[i]==3) cnt3++;
            }
            if(cnt1+cnt3>=m) cout<<1;
            else cout<<0;
        }
        else cout<<0;
        return 0;
    }
    else{
        int ans=-INT_MAX;
        for(int i=1;i<=n;i++){
            vis[i]=1;
            dfs(ans,1,a[i]);
            vis[i]=0;
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
