#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],idx[200010],vis[200010],ans;
void dfs(int step){
    if(step==m+1){
        int tot=a[idx[0]];
        for(int i=1;i<n;i++) tot&=a[idx[i]];
        ans=max(ans,tot);
    }
    else for(int i=0;i<n;i++){
            if(vis[i]==0&&i>a[step-1]){
                idx[step]=i;
                vis[i]=1;
                dfs(step+1);
                vis[i]=0;
            }
        }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        idx[i]=i+1;
    }
    sort(idx,idx+n);
    do{
        int tot=(1<<30)-1;
        cout<<tot<<" ";
        for(int i=0;i<m;i++) tot&=a[idx[i]];
        for(int i=0;i<m;i++) cout<<a[idx[i]]<<" ";
        cout<<tot<<"\n";
        ans=max(ans,tot);
    }while(next_permutation(idx,idx+n));
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
