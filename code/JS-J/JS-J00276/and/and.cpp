#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],maxx=-1;
long long ans=-1,t=-1,sum=-1;
void dfs(int x,int y){
    if(x==n+1){
        if(y==0){
            ans=max(ans,t);
            return;
        }
        else return;
    }
    if(t==-1){
        t=a[x];
        dfs(x+1,y-1);
        t=-1;
    }
    else{
        int t1=t;
        t=(t&a[x]);
        dfs(x+1,y-1);
        t=t1;
    }
    dfs(x+1,y);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
        if(sum==-1)sum=a[i];
        else sum=(sum&a[i]);
    }
    if(n<=20){
        dfs(1,m);
        cout<<ans;
        return 0;
    }
    if(m==1){
        cout<<maxx;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,1ll*a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==n){
        cout<<sum;
        return 0;
    }
    sort(a+1,a+1+n);
    cout<<a[m];
    return 0;
}
