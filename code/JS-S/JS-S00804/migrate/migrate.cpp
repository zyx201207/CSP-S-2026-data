#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3fll
const int N=505;
ll c,n,t,a[N],dis[N][N],minn,tot,d,ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        memset(dis,-1,sizeof(dis));
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<n;i++){
            if(a[i+1]-a[i]<=d)dis[i][i+1]=1;
        }
        for(int len=3;len<=n;len++){
            for(int l=1;l<=n-len+1;l++){
                int r=l+len-1;
                if(a[r]-a[l]<=d)dis[l][r]=1;
                else{
                    minn=INF,tot=0;
                    for(int k=l+1;k<r;k++){
                        if(dis[l][k]!=-1&&dis[k][r]!=-1){
                            if(dis[l][k]+dis[k][r]<=minn){
                                if(dis[l][k]+dis[k][r]<minn){
                                    minn=dis[l][k]+dis[k][r];
                                    tot=1;
                                }
                                else tot++;
                            }
                        }
                    }
                    if(tot==2)ans++;
                    if(minn!=INF)dis[l][r]=minn;
                }
                //cout<<dis[l][r]<<" "<<l<<" "<<r<<" "<<tot<<endl;
            }
        }
        cout<<ans<<endl;
        //cout<<cnt<<endl;
    }
    return 0;
}
/*
10 3
0 3 6 7 8 9 10 13 16 19
5 3
-3 0 2 3 4
*/
