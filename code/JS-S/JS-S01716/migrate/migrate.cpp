#include<bits/stdc++.h>
using namespace std;
long long b[15];
long long a[2000005],n,d;
void dfs(long long x,long long y,long long k){
    if(x==y){
        b[k]++;
        return ;
    }
    for(long long i=x+1;i<=y;++i){
        if(a[i]-a[x]<=d)dfs(i,y,k+1);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    if(c==1||c==2){
        while(t--){
            long long ans=0;
            cin>>n>>d;
            for(long long i=1;i<=n;++i){
                b[i]=0;
            }
            for(long long i=1;i<=n;++i)cin>>a[i];
            for(long long i=1;i<=n;++i){
                for(long long j=i+1;j<=n;++j){
                        for(long long k=1;k<=n;++k){
                            b[k]=0;
                        }
                    dfs(i,j,0);
                    for(long long k=1;k<=n;++k){
                        if(b[k]){
                            if(b[k]==2){
                                ans++;
                                cout<<i<<' '<<j<<endl;
                            }
                            else break;
                        }
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(long long i=1;i<=n;i++){
                cin>>a[i];
            }
            long long tmp=a[2]-a[1];
            long long tmp2=(d/tmp);
            long long tmp3=d*2;
            cout<<n-tmp3+1<<endl;
        }
    }
    return 0;
}
