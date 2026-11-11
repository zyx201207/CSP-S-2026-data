#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000005],len[5005][5005],cnt[5005][5005];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(c<=6||n<=300){
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++) len[i][j]=1e18;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++) cnt[i][j]=0;
            int ans=0;
            for(int i=1;i<=n;i++){
                len[i][i]=0;
                cnt[i][i]=1;
                for(int j=i+1;j<=n;j++){
                    for(int k=i;k<j;k++)
                        if(a[j]-a[k]<=d) len[i][j]=min(len[i][j],len[i][k]+1);
                    for(int k=i;k<j;k++)
                        if(a[j]-a[k]<=d&&len[i][k]+1==len[i][j]) cnt[i][j]+=cnt[i][k];
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=i;j<=n;j++){
                    //cout<<len[i][j]<<":"<<cnt[i][j]<<" ";
                    ans+=(cnt[i][j]==2);
                }
                //cout<<"\n";
            }
            cout<<ans<<"\n";
        }else/* if(c<=10||n<=5000)*/{
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++) len[i][j]=1e18;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++) cnt[i][j]=0;
            int ans=0;
            for(int i=1;i<=n;i++){
                map<int,int>mp;
                int l=i;
                len[i][i]=0;
                cnt[i][i]=1;
                mp[0]++;
                for(int j=i+1;j<=n;j++){
                    //cout<<l<<" ";
                    while(a[j]-a[l]>d){
                        mp[len[i][l]]-=cnt[i][l];
                        //cout<<len[i][l]<<'|'<<cnt[i][l]<<"|";
                        if(mp[len[i][l]]==0) mp.erase(mp.find(len[i][l]));
                        l++;
                        //cout<<l<<" ";
                    }
                    //cout<<i<<" "<<j<<" ";
                    //for(auto x:mp) cout<<x.first<<":"<<x.second<<" ";
                    //cout<<"\n";
                    len[i][j]=(*mp.begin()).first+1;
                    cnt[i][j]=(*mp.begin()).second;
                    mp[len[i][j]]+=cnt[i][j];
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=i;j<=n;j++){
                    //cout<<len[i][j]<<":"<<cnt[i][j]<<" ";
                    ans+=(cnt[i][j]==2);
                }
                //cout<<"\n";
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
