#include<bits/stdc++.h>
using namespace std;
int n,d;
vector<int> a;
vector<int> vis;
vector<int> cnt;
void dfs(int pos,int ed,int tmp){
    if(pos==ed){
        cnt[tmp]++;
    }
    else{
        for(int i=pos+1;i<=pos+d;i++){
            if(a[i]-a[pos]<=d){
                if(i<=n){
                    if(vis[i]==0){
                        vis[i]=1;
                        dfs(i,ed,++tmp);
                        vis[i]=0;
                    }
                }
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int ans=0;
        cin>>n>>d;
        a.resize(n+1);
        vis.resize(n+1);
        cnt.resize(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    vis[k]=0;
                    cnt[k]=0;
                }
                dfs(i,j,0);
                for(int i=1;;i++){
                    if(cnt[i]!=0){
                        if(cnt[i]==2)ans++;
                        break;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
