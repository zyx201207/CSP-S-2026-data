#include<bits/stdc++.h>
using namespace std;
bool a[5010][5010],b[5010];
int l[5010],cnt,ans;
void dfs(int n,int now,int e){
    if(now==e){
        cnt++;
        if(cnt==2)ans++;
        return;
    }
    b[now]=1;
    for(int i=1;i<=n;i++){
        if(a[now][i]&&!b[i])dfs(n,i,e);
    }
    b[now]=0;
}
int main(){
    freopen("migrate1.in","r",stdin);
    //freopen("migrare.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        memset(a,0,sizeof(a));
        ans=0;
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>l[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(abs(l[i]-l[j])<=d)a[i][j]=a[j][i]=1;
            }
        }
        for(int u=1;u<=n;u++){
            for(int v=u+1;v<=n;v++){
                dfs(n,u,v);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
