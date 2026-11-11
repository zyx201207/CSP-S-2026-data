#include <bits/stdc++.h>
using namespace std;
#define int long long
int x[2000005],dis[1005][1005],cnt[1005][1005];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        if(c<=6){
            sort(x+1,x+n+1);
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dis[i][j]=2e18;
                    cnt[i][j]=0;
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(x[j]-x[i]<=d){
                        dis[i][j]=dis[j][i]=1;
                        cnt[i][j]=cnt[j][i]=1;
                    }
                    else
                        break;
                }
            }
            for(int k=1;k<=n;k++){
                for(int i=1;i<=n;i++){
                    if(dis[i][k]==2e18)
                        continue;
                    for(int j=1;j<=n;j++){
                        if(dis[k][j]==2e18 || i==j || i==k || k==j)
                            continue;
                        if(dis[i][j]>dis[i][k]+dis[k][j]){
                            dis[i][j]=dis[i][k]+dis[k][j];
                            cnt[i][j]=cnt[i][k]*cnt[k][j];
                        }
                        else if(dis[i][j]==dis[i][k]+dis[k][j] && dis[i][j]!=1)
                            cnt[i][j]+=cnt[i][k]*cnt[k][j];
                    }
                }
            }
            int ans=0;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(cnt[i][j]==2 && dis[i][j]>1)
                        ans++;
                }
            }
            cout<<ans<<'\n';
        }
        else if(c==11 || c==12){
            int D=x[2]-x[1],tmp=1;
            //cout<<"### "<<n<<' '<<D<<' '<<d<<endl;
            if(d<=D){
                cout<<0<<endl;
                continue;
            }
            d=d-d%D;
            d=d*2-1;
            while(D*tmp<d)
                tmp++;
            if(n<tmp)
                cout<<0<<endl;
            else
                cout<<n-tmp+1<<endl;
        }
    }
    return 0;
}
