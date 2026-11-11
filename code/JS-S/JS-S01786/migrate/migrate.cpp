#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,INF=1e9;
int a[N],f[N],g[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,T,n,d;
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;++i) cin>>a[i];
        int ans=0;
        for(int i=1;i+3<=n;++i){
            f[i]=0;
            g[i]=1;
            for(int j=i+1;j<=n;++j){
                f[j]=INF;
                g[j]=0;
                for(int k=j-1;k>=i;--k){
                    if(a[j]-a[k]<=d){
                        if(f[k]+1<f[j]){
                            f[j]=f[k]+1;
                            g[j]=g[k];
                        }else if(f[k]+1==f[j]){
                            g[j]++;
                        }
                    }else break;
                }
                if(f[i]<INF&&g[j]==2){
                    ans++;
                    /*if(j-i>=4&&j-i<=10){
                        cout<<"d="<<d<<"  ";
                        for(int k=i;k<=j;++k) cout<<a[k]<<' ';
                        cout<<'\n';
                    }*/
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
