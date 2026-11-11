#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
int ans;
void dfs(int dep,int cnt,int s){
    if(dep>n||cnt==m){
        if(cnt==m)ans=max(ans,s);
        return;
    }
    if(cnt+n-dep+1<m)return;
    dfs(dep+1,cnt,s);
    dfs(dep+1,cnt+1,(s&a[dep]));
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    bool f=1;
    cin>>n>>m>>a[1];
    int s=a[1];
    int mx=a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        s=(s&a[i]);
        mx=max(mx,a[i]);
        if(a[i]>=4)f=0;
    }
    if(n==m){
        cout<<s;
    }
    else if(m==1)cout<<mx;
    else if(f){
        int s1,s2,s3;
        for(int i=1;i<=n;i++){
            if(a[i]==1)s1++;
            else if(a[i]==2)s2++;
            else if(a[i]==3)s3++;
        }
        if(s1+s2+s3<m)cout<<0;
        else if(s2+s3<m||s1+s3<m){
            cout<<0;
        }
        else {
            if(s3>=m)cout<<3;
            else if(s2+s3>=m)cout<<2;
            else if(s1+s3>=m)cout<<1;
        }
    }
    if(m==2){
        int ans=0;
        for(int i=1;i<=n;i++){
            int s=a[i];
            for(int j=i+1;j<=n;j++){
                s=(s&a[j]);
                ans=max(ans,s);
            }
        }
        cout<<ans;
    }
    else {
        for(int i=1;i<=n-m;i++){
            dfs(i+1,1,a[i]);
        }
        cout<<ans;
    }
    return 0;
}
