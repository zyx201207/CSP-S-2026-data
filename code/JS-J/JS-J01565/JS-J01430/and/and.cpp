#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],ans=0;
void dfs(int idx,int cnt){
    if(idx>n){
        if(cnt==m){
            int c=b[1];
            for(int i=2;i<=m;i++) c=(c&b[i]);
            ans=max(ans,c);
        }
        return;
    }
    dfs(idx+1,cnt);
    b[cnt+1]=a[idx];
    dfs(idx+1,cnt+1);
    b[cnt+1]=0;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,greater<int>());
    if(m==1){
        cout<<a[1];
        return 0;
    }
    if(n==m){
        int ccc=a[1];
        for(int i=2;i<=n;i++){
            ccc=(ccc&a[i]);
        }
        cout<<ccc;
    }
    if(m==2&&n<=2000){
        int res=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                res=max(res,(a[i]&a[j]));
            }
        }
        cout<<res;
    }
    if(n<=20){
        dfs(1,0);
        cout<<ans;
    }else{
        bool flag=1;
        for(int i=1;i<=n;i++){
            bool f=0;
            for(int j=1;j<=20;j++){
                if(a[i]+1==pow(2,j)) f=1;
            }
            if(!f) flag=0;
        }
        if(flag){
            sort(a+1,a+1+n,greater<int>());
            int cc=a[1];
            for(int i=2;i<=m;i++){
                cc=(cc&a[i]);
            }
            cout<<cc;
            return 0;
        }
        /*
        bool ff=1;
        for(int i=1;i<=n;i++){
            if(a[i]!=i-1) ff=0;
        }
        */
    }
    return 0;
}
