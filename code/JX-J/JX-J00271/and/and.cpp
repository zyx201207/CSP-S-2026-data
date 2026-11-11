#include<bits/stdc++.h>
using namespace std;
const int N=15005;
int n,m,maxs=0;
int a[N];
void dfs(int x,int cnt,int ans){
    if(cnt>m) return;
    if(x>n){
        if(cnt==m) maxs=max(ans,maxs);
        return;
    }
    if(cnt==0){
        dfs(x+1,1,a[x]);
        dfs(x+1,0,0);
    }else{
        dfs(x+1,cnt+1,(ans & a[x]));
        dfs(x+1,cnt,ans);
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=20){
        dfs(1,0,0);
        cout<<maxs;
    }else{
        if(m==1){
            for(int i=1;i<=n;i++) maxs=max(maxs,a[i]);
            cout<<maxs;
        }else if(m==n){
            maxs=a[1];
            for(int i=2;i<=n;i++) maxs=maxs & a[i];
            cout<<maxs;
        }else if(m==2){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i!=j) maxs=max(maxs,(a[i] & a[j]));
                }
            }
            cout<<maxs;
        }else cout<<0;
    }
    return 0;
}
