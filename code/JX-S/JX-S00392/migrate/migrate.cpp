#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(int &a){
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return a=x*f;
}
const int N=310;
int dist[N][N];
int f[N][N][N];
int n,m,ans;
int st[N][N][N];
int c,t,d;
int a[N];
int cnt[N][N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    read(c),read(t);
    while(t--){
        read(n),read(d);
        memset(dist,0,sizeof dist);
        memset(f,0,sizeof f);
        memset(st,0,sizeof st);
        ans=0;
        for(int i=1;i<=n;i++){
            read(a[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=a[j]-a[i];
                if(dist[i][j]==0)f[i][j][0]=1;
                else if(d>=dist[i][j])f[i][j][1]=1;
            }
        }
        for(int len=1;len<=n;len++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    for(int k=1;k<=n;k++){
                        for(int d=0;d<=len;d++){
                            f[i][k][len]+=f[i][j][d]+f[j][k][len-d];
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int len=1;len<=n;len++){
                    if(f[i][j][len]){
                        if(f[i][j][len]==2)ans++;
                        else break;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}