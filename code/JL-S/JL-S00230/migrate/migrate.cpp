#include <bits/stdc++.h>
using namespace std;
int c;
long long h,a[2000001];
long long dis[10001][10001];
long long f[10001][10001];
long long ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>h;
    while(h--){
        ans=0;
        memset(dis,21487647,sizeof(dis));
        memset(f,0,sizeof(f));
        int k,strength;
        cin>>k>>strength;
        for(int i=0;i<k;i++){
            cin>>a[i];
            if(i>=1&&a[i]-a[i-1]<=strength){
                dis[i-1][i]=1;
            }
        }
        for(int i=0;i<k;i++){
            for(int j=i+1;j<k;j++){
                if(a[j]-a[i]<=strength){
                    dis[i][j]=1;
                }
            }
        }
        for(int i=0;i<k;i++){
            for(int j=i+1;j<k;j++){
                for(int kop=i+1;kop<j;kop++){
                    dis[i][j]=min(dis[i][j],dis[i][kop]+dis[kop][j]);
                }
            }
        }
        for(int i=0;i<k;i++){
            for(int j=i+1;j<k;j++){
                for(int kop=i+1;kop<j;kop++){
                    if(dis[i][j]==dis[i][kop]+dis[kop][j]) f[i][j]++;
                }
            }
        }
        for(int i=0;i<k;i++){
            for(int j=i+1;j<k;j++){
                if(f[i][j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
