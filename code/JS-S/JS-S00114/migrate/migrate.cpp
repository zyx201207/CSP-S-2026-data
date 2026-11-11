#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=2e6+5;
int f[N][N],cnt[N][N],a[M];

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        memset(f,-1,sizeof(f));
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++){
            f[i][i]=0,cnt[i][i]=1;
            for(int j=i-1;a[i]-a[j]<=d&&j;j--)
                for(int k=1;k<=j;k++){
                    if(f[k][j]+1==f[k][i])cnt[k][i]+=cnt[k][j];
                    else if(f[k][i]>f[k][j]+1||f[k][i]==-1)
                        f[k][i]=f[k][j]+1,cnt[k][i]=cnt[k][j];
                }
        }
        int res=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                res+=(cnt[i][j]==2);
        cout<<res<<'\n';
    }
}
