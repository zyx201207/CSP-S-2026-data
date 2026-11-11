#include<bits/stdc++.h>
using namespace std;
struct niko{
    long long val;
    int cnt;
};
long long x[2000005];
niko dis[5005][5005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--){
        int n;long long d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j] = {0x3f,1};
            }
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(x[i]+d>=x[j]){
                    dis[i][j] = {1,1};
                }else{
                    break;
                }
            }
        }
        for(int l=n;l>=1;l--){
            for(int len=1;len<=n&&l+len-1<=n;len++){
                int r = l+len-1;
                for(int k=l+1;k<r;k++){
                    if(dis[l][k].val+dis[k][r].val<dis[l][r].val){
                        dis[l][r] = {dis[l][k].val+dis[k][r].val,1};
                    }else if(dis[l][k].val+dis[k][r].val==dis[l][r].val){
                        dis[l][r].cnt++;
                    }
                }
            }
        }
        int ans = 0;
        for(int l=1;l<=n;l++){
            for(int r=l+1;r<=n;r++){
                if(dis[l][r].cnt==2){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
