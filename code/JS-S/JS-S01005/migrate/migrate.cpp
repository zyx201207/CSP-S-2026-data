#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,stp,ans,maxn=310;
long long a[2000010],s[310][310];
bool vis[310][310],vis_[310][310];
void qk(){
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++) vis[i][j]=vis_[i][j];
}
void work(int x,int y,int L){
    if(x==y){
        if(L==maxn) stp++;
        if(L<maxn){
            maxn=L;
            stp=1;
        }
        cout<<L<<" "<<maxn<<" "<<stp<<endl;
    }
    for(int i=x+1;i<=y;i++){
        if(vis[x][i]!=1&&vis[i][y]!=1){
            vis[x][i]=vis[i][y]=1;
            work(i,y,L+1);
            vis[x][i]=vis[i][y]=0;
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(n<=300){
            for(int i=1;i<n;i++)
                for(int j=i+1;j<=n;j++){
                    s[i][j]=a[j]-a[i];
                }
            for(int i=1;i<=n;i++)
                for(int j=i;j<=n;j++){
                    if(s[i][j]>d) vis_[i][j]=vis[i][j]=1;
                }

            for(int i=1;i<n;i++){
                for(int j=i+1;j<=n;j++){
                    qk();
                    stp=0;
                    maxn=310;
                    work(i,j,0);
                    //cout<<stp<<" ";
                    //cout<<i<<" "<<j<<" "<<stp<<endl;
                    if(stp==2) ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
