#include<bits/stdc++.h>
using namespace std;
int c,T,n,s[5005][5005],v[5005],ans;
long long d,a[5005];
void dfs(int x,int y,int t){
    for(int i=y+1;i<=n;i++){
        if(s[x][i]>=t+s[y][i]){
            s[x][i]=t+s[y][i];
            dfs(x,i,t+s[y][i]);
            continue;
        }
        break;
    }
    return;
}
void vis(int x,int t){
    for(int i=x+1;i++;i<=n){
        if(s[x][i]==t+1){
            v[i]++;
            vis(i,t+1);
            continue;
        }
        break;
    }
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<n;i++){
            memset(s,0x3f,sizeof(s));
            memset(v,0,sizeof(v));
            for(int j=1;j<n;j++){
                for(int k=j+1;k<=n;k++){
                    if(a[k]-a[j]<=d){
                        s[j][k]=1;
                    }
                }
            }
            dfs(i,i+1,0);
            vis(i,0);
            for(int j=i+1;j<=n;j++){
                if(v[j]==2)ans++;

            }
        }
        cout<<ans;
        if(T)cout<<endl;
    }
    return 0;
}
