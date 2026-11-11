#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000005,M=5005;
int a[N];
int dis[M][M],ct[M][M];
int n,d;
void work1(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) dis[i][j]=ct[i][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]-a[i]<=d){
                dis[i][j]=1;
                ct[i][j]=1;
            }
        }
    }
    int ans=0;
    for(int i=n;i>=1;i--){
        int x=0,y=0,z=0;
        for(int j=i+1;j<=n;j++){
            if(ct[i][j]==1){
                x=y;
                y=z;
                z=j;
                continue;
            }
            ct[i][j]+=ct[z][j];
            if(dis[y][j]==dis[z][j]) ct[i][j]+=ct[y][j];
            if(dis[x][j]==dis[z][j]) ct[i][j]+=ct[x][j];
            dis[i][j]=dis[z][j]+1;
            if(ct[i][j]==2) ans++;
        }
    }
    cout<<ans<<'\n';
}
void work2(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1){
        cout<<0<<'\n';
        return;
    }
    int de=a[2]-a[1];
    int t=d/de;
    if(t<=1){
        cout<<0<<'\n';
        return;
    }
    t*=2;
    if(t>n){
        cout<<0<<'\n';
        return;
    }
    cout<<n-t+1<<'\n';
}
int last[N];
void work3(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1,j=1;i<=n;i++){
        while(j+1<=n&&a[j+1]-a[i]<=d) j++;
        last[i]=j;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(last[i]==i+1) continue;
        int l=last[i]+1;
        int r=min(last[last[i]],last[last[i]-1]);
        if(last[i]-2>i){
            int t=last[last[i]-2]+1;
            l=max(l,t);
        }
        if(l<=r) ans+=r-l+1;
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--){
        // work3();
        if(c<=10) work1();
        if(c>=11&&c<=12) work2();
        if(c>=13&&c<=14) work3();
    }
    return 0;
}