//1~6,11~12:8*4=32
#include<bits/stdc++.h>
using namespace std;
const int N=5001;
long long x[N];int f[N],d[N][N],cnt[N][N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;cin>>c>>t;
    int n;long long m;
if(c<=10){
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>x[i];
        memset(d,63,sizeof(d));
        for(int l=1;l<n;l++)for(int i=1;i<=n-l;i++){
            int j=i+l;
            if(x[j]-x[i]<=m)d[i][j]=1;
            else for(int k=i+1;k<j&&x[k]-x[i]<=m;k++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        }
        int ans=0;
        memset(cnt,0,sizeof(cnt));
        for(int l=1;l<n;l++)for(int i=1;i<=n-l;i++){
            int j=i+l;
            if(x[j]-x[i]<=m)cnt[i][j]=1;
            else for(int k=i+1;k<j&&x[k]-x[i]<=m;k++)if(d[i][k]+d[k][j]==d[i][j])cnt[i][j]+=cnt[i][k]*cnt[k][j];
            if(cnt[i][j]==2)ans++;
            else if(cnt[i][j]>2)cnt[i][j]=3;
        }
        cout<<ans<<'\n';
    }
}else if(c>=11&&c<=12){
    int a,b,l;
    while(t--){
        cin>>n>>m>>a>>b;
        l=b-a;
        for(int i=2/*major*/;i*2<=n;i++)if(i*l<=m&&(i+1)*l>m){
            cout<<n-i-i+1<<'\n';
            break;
        }
    }
}else if(c>=13&&c<=14){
    int
}
    return 0;
}
