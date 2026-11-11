#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
const int N=2e5+5;
int a[N];
int maxn;
bool vis[N];
bool cmp(int x,int y){
    return x>y;
}
void dfs(int k,int x){
    if(k==m){
        ans=max(ans,x);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(k+1,x&a[i]);
            vis[i]=0;
        }
    }
}
int cntt[4];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
    if(maxn<=3){
        for(int i=1;i<=n;i++) cntt[a[i]]++;
        if(cntt[3]>=m) cout<<3;
        else if(cntt[2]+cntt[3]>=m) cout<<2;
        else cout<<1;
        return 0;
    }
    if(n<=20){
        dfs(0,(1<<30)-1);
        cout<<ans<<"\n";
        return 0;
    }
    if(n<=2000){
        if(m==1){
            for(int i=1;i<=n;i++) ans=max(ans,a[i]);
            cout<<ans<<endl;
            return 0;
        }
        if(m==n){
            ans=(1<<30)-1;
            for(int i=1;i<=n;i++) ans&=a[i];
            cout<<ans<<endl;
            return 0;
        }
        if(m==2){
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    ans=max(ans,a[i]&a[j]);
                }
            }
            cout<<ans<<endl;
            return 0;
        }
    }else{
        sort(a+1,a+n+1,cmp);
        ans=a[1];
        for(int i=2;i<=m;i++) ans&=a[i];
        cout<<ans;
    }
    return 0;
}
//g++ and.cpp -o and; ./and; diff and.out and1.ans