#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans=INT_MIN,dp[N];
bool vis[N];
void dfs(int v,int dep,int x){
    if(dep==m){
        ans=max(ans,v);
        return;
    }
    if(x==n)return;
    for(int i=x+1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            dfs(v&a[i],dep+1,i);
            vis[i]=0;
        }
    }
    return;
}
int cnt=INT_MAX,mxai;
int main()
{
//#ifndef ZHOUYUDEBUG666
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
//#endif
    std::ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt=cnt&a[i];
        mxai=max(mxai,a[i]);
    }
    if(n==m)cout<<cnt<<endl;
    else if(mxai<4){
        int cnt1=0,cnt2=0,cnt3=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1)cnt1++;
            if(a[i]==2)cnt2++;
            if(a[i]==3)cnt3++;
        }
        if(cnt3>=m)cout<<3<<endl;
        else if(cnt2>=m)cout<<2<<endl;
        else if(cnt2+cnt3>=m)cout<<2<<endl;
        else if(cnt1+cnt3>=m)cout<<1<<endl;
        else if(cnt1>=m)cout<<1<<endl;
        else cout<<0<<endl;
    }else {
        for(int i=1;i<=n-m+1;i++){vis[i]=1;dfs(a[i],1,i);vis[i]=0;}
        cout<<ans<<endl;
    }
    return 0;
}


