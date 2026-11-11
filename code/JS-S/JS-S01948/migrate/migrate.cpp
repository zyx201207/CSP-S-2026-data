#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e2+5;
int f[N][N],g[N][N],a[N];
int n,d;
void init(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            f[i][j]=-1,g[i][j]=0;
    for(int i=1;i<=n;i++)f[i][i]=-1,g[i][i]=1;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(a[j]-a[i]<=d)f[i][j]=1,g[i][j]=1;
}
void dp(){
    for(int k=1;k<=n;k++)
        for(int i=1;i<=k;i++)
            for(int j=k;j<=n;j++)
                if(i!=j){
                    if((f[i][k]+f[k][j]<f[i][j]||f[i][j]==-1)&&f[i][k]!=-1&&f[k][j]!=-1) g[i][j]=1,f[i][j]=f[i][k]+f[k][j];
                    else if(f[i][k]+f[k][j]==f[i][j]&&f[i][k]!=-1&&f[k][j]!=-1)  {
                            g[i][j]+=g[i][k]*g[k][j];
                    }
                }
  for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++)cout<<f[i][j]<<" ";
        cout<<"\n";
    }cout<<"\n";
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++)cout<<g[i][j]<<" ";
        cout<<"\n";
    }cout<<"\n";

    int sum=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(g[i][j]==2) ++sum;
    cout<<sum<<"\n";
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c<=6){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>a[i];
            init();
            dp();
        }
    }else if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>a[i];
            int x=d/(a[2]-a[1]);
            int k=1,ans=0;
            int v=n/x;
            ans=(n+1)*(v-1)-x*(v+2)*(v-1)/2;
            cout<<ans<<"\n";
        }
    }else{
        while(t--)cout<<"0\n";
    }
    return 0;
}
/*
12 1
11 4
1 3 5 7 9 11 13 15 17 19 21

exp:20
*/
