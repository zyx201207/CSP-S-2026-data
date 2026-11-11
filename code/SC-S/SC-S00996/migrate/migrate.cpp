#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
using PII=pair<int,int>;
const int N=505,INF=3e18;
int c,t;
int x[2000005];PII dis[N][N];
signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,d;cin>>n>>d;
        //int flg=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            //if(i>=3&&x[i]-x[i-1]!=x[2]-x[1]) flg=1;
        }
        // if(flg==0){
        //     int dd=x[2]-x[1];
        //     int num=d/dd;
        //     int ans=0;
        //     for(int i=num+2;i<=n;i++){
        //         ans+=(i-num-1)-max((int)0,i-2*num+1)+1;
        //     }
        //     cout<<ans<<"\n";
        //     continue;
        // }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(i==j) dis[i][j]={0,1};
                else dis[i][j]={INF,0};
            }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[i]>d) break;
                dis[i][j]={1,1};
            }
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<k;i++)
                for(int j=k+1;j<=n;j++){
                    if(dis[i][j].first>dis[i][k].first+dis[k][j].first){
                        dis[i][j]={dis[i][k].first+dis[k][j].first,dis[i][k].second*dis[k][j].second};
                    }else if(dis[i][j].first==dis[i][k].first+dis[k][j].first){
                        dis[i][j].second+=dis[i][k].second*dis[k][j].second;
                    }
                }
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(dis[i][j].second==2){
                    ans++;
                    //cout<<i<<" "<<j<<"\n";
                }
    //     for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++)
    //         cout<<dis[i][j].second<<" ";
    //     cout<<"\n";
    // }
        cout<<ans<<"\n";
    }
    return 0;
}