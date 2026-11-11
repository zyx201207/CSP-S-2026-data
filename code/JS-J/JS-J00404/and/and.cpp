#include<bits/stdc++.h>
using namespace std;
int n,m;
bool a[200005][35];
int b[200005];
bool vis[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        vis[i]=1;
    }
    b[0]=(1LL<<31)-1;
    for(int i=1;i<=n;i++){
        int x,cnt=1;
        cin>>b[i];
        x=b[i];
        while(x){
            a[i][cnt]=x&1;
            x>>=1;
            cnt++;
        }
    }
    for(int i=31;i>=1;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(a[j][i]==1&&vis[j]==1)cnt++;
        }
        if(cnt==m){
            int ans=b[0];
            for(int j=1;j<=n;j++){
                if(a[j][i]==1&&vis[j]==1)ans&=b[j];
            }
            cout<<ans;
            return 0;
        }
        if(cnt>m){
            for(int j=1;j<=n;j++){
                if(a[j][i]==0)vis[j]=0;
            }
        }
    }
    int ans=b[0],cnt=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==1){
            ans&=b[i];
            cnt++;
        }
        if(cnt==m){
            cout<<ans;
            return 0;
        }
    }
    return 0;
}
