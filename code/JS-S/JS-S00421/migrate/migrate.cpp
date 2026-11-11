#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,a[5005],dist[5005],cnt[5005];
bool check(int x,int y){
    for(int i=x;i<=y;i++){
        dist[i]=2e9,cnt[i]=0;
    }
    dist[x]=1,cnt[x]=1;
    for(int i=x+1;i<=y;i++){
        int minn=2e9,tmp=0;
        for(int j=i-1;j>=x;j--){
            if(a[i]-a[j]<=d){
                if(dist[j]+1<minn){
                    minn=dist[j]+1,tmp=cnt[j];
                }else if(dist[j]+1==minn){
                    tmp+=cnt[j];
                }
            }
        }
        dist[i]=minn,cnt[i]=tmp;
    }
    return cnt[y]==2;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(check(i,j)){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}
