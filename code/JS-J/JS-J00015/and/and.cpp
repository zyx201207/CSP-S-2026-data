#include<bits/stdc++.h>
using namespace std;
int a[200005],n;set<int>st;
set<int>dfs(int start,int m){
    set<int>s,tmp;
    if(n-start+1<m){s.insert(0);return s;}
    if(m==1){
        for(int i=start;i<=n;i++)s.insert(a[i]);
        return s;
    }
    if(n-start+1==m){
        int res=a[start];
        for(int i=start+1;i<=n;i++)res&=a[i];
        s.insert(res);
        return s;
    }
    for(int i=start;i<=n;i++){
        tmp=dfs(start+1,m-1);
        for(auto x:tmp)s.insert(a[i]&x);
    }
    return s;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int m,ans=0;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1)for(int i=1;i<=n;i++)ans=max(ans,a[i]);
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
    }else if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++)ans&=a[i];
    }else{
        st=dfs(1,m);
        for(auto x:st)ans=max(ans,x);
    }
    cout<<ans;
    return 0;
}
