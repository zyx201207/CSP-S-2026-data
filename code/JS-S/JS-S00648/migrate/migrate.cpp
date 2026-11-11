#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int c,T,n,d,a[N],fst[N],cnt[N][N],mx[N][N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        memset(cnt,0,sizeof(cnt));
        memset(fst,0,sizeof(fst));
        memset(mx,-1,sizeof(mx));
        int ans=0;
        if(n>=N) break;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(a[i]+d>=a[j]){
                    fst[i]=j;
                }else break;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int k=i,now=0;
                while(k<j){
                    if(fst[k]==k){
                        now=-1;
                        break;
                    }
                    now++;
                    k=fst[k];
                }
                if(now!=-1){
                    if(mx[i][j]>now||mx[i][j]==-1){
                        mx[i][j]=now;
                        cnt[i][j]=1;
                    }else if(mx[i][j]==now) cnt[i][j]++;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(cnt[i][j]==2) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
