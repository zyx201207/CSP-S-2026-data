#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int n,m,anss;
int a[maxn];
int maxx,sum;
void dfs(int x,int step,int ans){
    if(step==m){
        anss=max(anss,ans);
        return;
    }
    for(int i=x+1;i<=n;i++){
        dfs(i,step+1,ans&a[i]);
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    sum=a[1];
    maxx=a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
        sum&=a[i];
    }
    if(m==1){
        cout<<maxx;
        return 0;
    }
    if(m==2){
        int maxx=-1;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                maxx=max(maxx,a[i]&a[j]);
            }
        }
        cout<<maxx;
        return 0;
    }
    if(m==n){
        cout<<sum;
        return 0;
    }
    if(m==n-1){
        int maxxx=-1;
        for(int i=1;i<=n;i++){
            maxxx=max(maxxx,sum&a[i]);
        }
        cout<<maxxx;
        return 0;
    }
    for(int i=1;i<=n;i++){
        dfs(i,1,a[i]);
    }
    cout<<anss;
    return 0;
}
