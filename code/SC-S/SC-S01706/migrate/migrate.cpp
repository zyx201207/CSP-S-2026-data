#include<bits/stdc++.h>
const int N=2e6+11;
using namespace std;
int c,t;
int n;
long long d;
long long x[N];
long long dist[5010][5010];
int cnt[5010][5010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i <= n;i++){
            cin>>x[i];
        }
        if(n<=300){
            for(int i=1;i <= n;i++){
                dist[i][i]=0;
                for(int j=i-1;j > 0;j--){
                    dist[j][i]=0x3f3f3f3f3f3f3f3f;
                    for(int k=j+1;k <= i;k++){
                        if(x[k]-x[j]<=d) dist[j][i]=dist[k][i]+1;
                        else break;
                    }
                }
            }
            for(int i=1;i <= n;i++){
                cnt[i][i]=1;
                for(int j=i-1;j > 0;j--){
                    int lst=0;
                    cnt[j][i]=0;
                    if(dist[j][i]>=0x3f3f3f3f3f3f3f3f) continue;
                    for(int k=j+1;k <= i;k++){
                        if(x[k]-x[j]<=d){
                            if(k==j+1||dist[k][i]!=dist[k-1][i]){
                                lst=cnt[k][i];
                            }else{
                                lst+=cnt[k][i];
                                if(lst>2) lst=3;
                            }
                        }else{
                            break;
                        }
                    }
                    cnt[j][i]=lst;
                }
            }
            int ans=0;
            for(int i=1;i <= n;i++){
                for(int j=i+1;j <= n;j++){
                    if(cnt[i][j]==2) ans++;
                }
            }
            cout<<ans<<"\n";
        }else if(n<=5000){
            for(int i=1;i <= n;i++){
                dist[i][i]=0;
                int k=i;
                for(int j=i-1;j > 0;j--){
                    dist[j][i]=0x3f3f3f3f3f3f3f3f;
                    while(x[k]-x[j]>d) k--;
                    dist[j][i]=dist[k][i]+1;
                }
            }
            for(int i=1;i <= n;i++){
                int l=i,r=i;
                long long cn=1;
                cnt[i][i]=1;
                for(int j=i-1;j > 0;j--){
                    cnt[j][i]=0;
                    if(dist[j][i]>=0x3f3f3f3f3f3f3f3f) continue;
                    while(l>j+1&&dist[l-1][i]==dist[r][i]){
                        cn+=cnt[--l][i];
                    }
                    while(x[r]-x[j]>d){
                        cn-=cnt[r--][i];
                    }
                    if(r<l){
                        cn=cnt[r][i];
                        l=r;
                        while(l>j+1&&dist[l-1][i]==dist[r][i]){
                            cn+=cnt[--l][i];
                        }
                    }
                    cnt[j][i]=min(cn,3ll);
                }
            }
            int ans=0;
            for(int i=1;i <= n;i++){
                for(int j=i+1;j <= n;j++){
                    if(cnt[i][j]==2) ans++;
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}