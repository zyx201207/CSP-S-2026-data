#include<bits/stdc++.h>
using namespace std;
long long a[500005]{},b[500005]{},last[300005]{},cnt[300005]{},vis[300005]{};
void dfs(int i,int n){
    if(i>=n){
        return;
    }
    cnt[a[i+1]]+=cnt[a[i]];
    dfs(last[a[i+1]],n);
    if(i+1!=last[a[i+1]]){
       dfs(i+1,n);
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,minn=0x3f3f3f3f;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
        last[a[i]]=i;
    }
    for(long long i=1;i<=m;i++){
        minn=min(minn,last[i]);
    }
    dfs(minn,n);
    for(long long i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
