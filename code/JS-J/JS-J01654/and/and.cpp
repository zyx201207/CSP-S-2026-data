#include<bits/stdc++.h>
using namespace std;
long long ans=0;
void dfs(int st,long long sum,int id,int& n,vector<bool>& vis,vector<long long>& a){
    vis[st]=1;
    if(id==1){
        ans=max(ans,sum);
        if(vis[1]==1 and vis[4]==1 and vis[5]==1)
        vis[st]=0;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==1) continue;
        dfs(i,sum&a[i],id-1,n,vis,a);
    }
    vis[st]=0;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n=0,m;
    cin>>n>>m;
    vector<long long> a(n+2);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<long long> maxa=a;
    if(m==1){
        sort(maxa.begin()+1,maxa.begin()+n+1,greater<int>());
        cout<<maxa[1];
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    long long check=1;
    bool can=1;
    for(int i=0;i<m;i++){
        check*=n-i;
        if(check>1E7) can=0;
    }
    if(can){
        for(int i=1;i<=n;i++){
            vector<bool> vis(n+2,0);
            dfs(i,a[i],m,n,vis,a);
        }
        cout<<ans;
    }else{
        sort(maxa.begin()+1,maxa.begin()+n+1,greater<int>());
        ans=maxa[1];
        for(int i=2;i<=m;i++){
            ans&=maxa[i];
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}