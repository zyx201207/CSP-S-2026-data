#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],ans=0;
bool used[200005];
void dfs(long long pos){
    if(pos==m+1){
        long long s=0;
        for(int i=1;i<=n;i++){
            if(used[i]==1){
                if(s==0) s=a[i];
                else s&=a[i];
            }
        }
        ans=max(ans,s);
        return;
    }
    long long h=0;
    for(int i=1;i<=n;i++){
        if(!used[i] && h<=m){
            used[i]=1;
            dfs(pos+1);
            used[i]=0;
        }
    }
}
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
