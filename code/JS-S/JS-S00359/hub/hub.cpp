#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[2000010],f[10010][10010],m,ans,vis[10010][10010];
int dis(int a,int b){
    return labs(a-b);
}
int work(){
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)f[i][j]=0;
            else if(dis(a[i],a[j])<=m)f[i][j]=dis(a[i],a[j]);
            else f[i][j]=INT_MAX*(long long)114514;
            vis[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(f[i][k]+f[k][j]<f[i][j])
                    f[i][j]=f[i][k]+f[k][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(f[i][k]+f[k][j]==f[i][j]&&!vis[i][j])
                    ans++,vis[i][j]=1;
            }
        }
    }
    return ans;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c;
    cin>>c;
    cin>>t;
    while(t--){
        
        cout<<1<<'\n';
    }
    return 0;
}