#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=2e6+5,N=5e3+5,inf=0x3f3f3f3f3f3f3f3f;
int c,T,n,d,a[M],f[N][N],g[N][N];//1,2,>2?
void work(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(c<=6){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=inf,g[i][j]=0;
        for(int i=1;i<=n;i++)f[i][i]=0,g[i][i]=1;
        for(int l=2;l<=n;l++){
            for(int i=1;i+l-1<=n;i++){
                int j=i+l-1;
                if(a[j]-a[i]<=d){f[i][j]=g[i][j]=1;continue;}
                for(int k=i+1;k<j;k++){
                    if(a[k]-a[i]>d)break;
                    int t=f[k][j];
                    if(t+1<f[i][j])f[i][j]=t+1,g[i][j]=g[k][j];
                    else if(t+1==f[i][j]){
                        if(g[i][j]+g[k][j]>2)g[i][j]=3;
                        else g[i][j]=g[i][j]+g[k][j];
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(g[i][j]==2)ans++;
        cout<<ans<<"\n";
        return;
    }
    if(c>=11&&c<=12){
        if(n==1)return cout<<"0\n",void();
        int kt=a[2]-a[1];
        int k=d/kt;
        if(k<=1)return cout<<"0\n",void();
        cout<<max(0ll,n-2*k+1)<<"\n";
        return;
    }
    if(c>=13&&c<=14){
        int ans=0;
        for(int i=1;i<=n;i++){
            int t=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
            if(t==n)break;
            if(i+1==t)continue;
            int p1=upper_bound(a+1,a+n+1,a[t-1]+d)-a-1;
            if(i+2==t){ans+=p1-t;continue;}
            int p2=upper_bound(a+1,a+n+1,a[t-2]+d)-a-1;
            ans+=p1-p2;
        }
        cout<<ans<<"\n";
        return;
    }
    cout<<"0\n";
    return;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--)work();
    return 0;
}
