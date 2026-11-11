#include <bits/stdc++.h>
using namespace std;

const int N=500005,M=300005;

int n,m;
int a[N],cnt[M],ans[M];

int solve(int x){
    int ret=x;
    vector<bool> vis(m+1);

    for(int i=x;i<=n;i++){
        if(vis[a[i]]){
            ret=i;
        }
        else{
            vis[a[i]]=1;
        }
    }

    return ret;
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]=i;
    }

    for(int i=1;i<=n;i++){
        int p=solve(i);
        for(int j=p;j<=n;j++){
            ans[a[j]]++;
        }
    }

    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}