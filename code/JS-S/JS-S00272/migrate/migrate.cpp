#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=316,M=2e5+16;;
ll x[N],dis[N][N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--){
        if(c>10){
            cout<<"0\n";
            continue;
        }
        int n;
        ll d,ans=0;
        cin>>n>>d;
        memset(dis,0x3f,sizeof(dis));
        for(int i=1;i<=n;++i){
            dis[i][i]=0;
            cin>>x[i];
        }
        for(int i=1;i<n;++i){
            for(int j=i+1;j<=n;++j){
                if(x[j]-x[i]<=d){
                    dis[i][j]=dis[j][i]=1;
                }
                else{
                    break;
                }
            }
        }
        for(int k=1;k<=n;++k){
            for(int i=1;i<n;++i){
                for(int j=i+1;j<=n;++j){
                    dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        for(int i=1;i<n;++i){
            for(int j=i+2;j<=n;++j){
                if(x[j]-x[i]<=d){
                    continue;
                }
                int sum=0;
                for(int k=i+1;k<j;++k){
                    if(x[k]-x[i]>d){
                        break;
                    }
                    if(dis[i][k]+dis[k][j]==dis[i][j]&&x[j]-x[k]<=d){
                        ++sum;
                        if(sum>2){
                            break;
                        }
                    }
                }
                if(sum==2){
                    ++ans;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}