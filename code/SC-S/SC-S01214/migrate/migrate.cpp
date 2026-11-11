#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,ans,a[2000006],fl[3006][3006],cnt[3006][3006];
// vector<pair<int,int> > g[2000006];
// proirity_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c<=10){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>a[i];
            ans=0;
            memset(fl,0x3f,sizeof fl);
            memset(cnt,0,sizeof cnt);
            // cout<<"连边\n";
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(abs(a[i]-a[j])<=d){
                        // g[u].push_back({v,1)});
                        // g[v].push_back({u,1)});
                        fl[i][j]=fl[j][i]=1;
                        cnt[i][j]=cnt[j][i]=1;
                        // cout<<i<<' '<<j<<' '<<abs(a[i]-a[j])<<'\n';
                    }
                }
            }
            // cout<<"路径\n";
            for(int k=1;k<=n;k++){
                for(int i=1;i<=n;i++){
                    if(i==k) continue;
                    for(int j=1;j<=n;j++){
                        if(i==j||j==k) continue;
                        if(fl[i][j]>fl[i][k]+fl[k][j]){
                            fl[i][j]=fl[i][k]+fl[k][j];
                            cnt[i][j]=cnt[i][k]*cnt[k][j];
                            // cout<<"大于"<<i<<"->"<<k<<"->"<<j<<' '<<cnt[i][j]<<'\n';
                        }
                        else if(fl[i][j]==fl[i][k]+fl[k][j]){
                            cnt[i][j]+=cnt[i][k]*cnt[k][j];
                            // cout<<"相等"<<i<<"->"<<k<<"->"<<j<<' ';
                            // cout<<cnt[i][k]<<' '<<cnt[k][j]<<' '<<cnt[i][j]<<'\n';
                        }
                    }
                }
            }
            // cout<<"答案\n";
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++){
                    if(cnt[i][j]==2){
                        ans++;
                        // cout<<i<<' '<<j<<'\n';
                    }
                }
            cout<<ans<<'\n';
        }
    }
    return 0; 
}