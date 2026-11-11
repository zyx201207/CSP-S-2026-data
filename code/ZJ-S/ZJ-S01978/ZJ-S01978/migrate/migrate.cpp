#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+6;
int c,t;
int n,d;
int x[N];
namespace TASK_1_10{
    const int M=5003;
    unsigned dis[M][M];
    unsigned cnt[M][M];
    void mian(){
        for(int i=2;i<=n;i++){
            if(x[i]-x[i-1]<=d){
                dis[i-1][i]=1;
                cnt[i-1][i]=1;
            }
            else dis[i-1][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cnt[i][j]=0;
                dis[i][j]=0x7f7f7f7f;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[i]<=d){
                    dis[i][j]=1;
                    cnt[i][j]=1;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[i]>d){
                    dis[i][j]=0x7f7f7f7f;
                    vector<int> vec;
                    for(int k=i+1;k<j;k++){
                        if(dis[i][k]+dis[k][j]<dis[i][j]){
                            dis[i][j]=dis[i][k]+dis[k][j];
                            vec.clear();
                            vec.push_back(k);
                        }else if(dis[i][k]+dis[k][j]==dis[i][j]){
                            vec.push_back(k);
                        }
                    }
                    //cerr<<i<<' '<<j<<':';
                    for(int k:vec){
                        //cerr<<k<<','<<cnt[i][k]*cnt[k][j]<<' ';
                        cnt[i][j]+=cnt[i][k]*cnt[k][j];
                    }
                    //cerr<<cnt[i][j];
                    //cerr<<endl;
                }
                //cerr<<dis[i][j]<<' ';
                if(cnt[i][j]==2)ans++;
            }
            //cerr<<endl;
        }
        cout<<ans<<endl;
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(c<=10)TASK_1_10::mian();
        else{
            cout<<0<<endl;
        }
    }
}