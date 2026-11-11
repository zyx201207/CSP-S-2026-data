#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,T;
int n,m,pos[N],ans;
int shuang[N],yi[N],minn[N];
int pre[N];
inline void solve(){
    cin>>n>>m;
    ans=0;
    int t=1;
    for(int i=1;i<=n;i++){
        cin>>pos[i];
        yi[i]=0;
        shuang[i]=0;
        while(pos[i]-pos[t]>m){
            t++;
        }
        pre[i]=t;
    }
    for(int i=1;i<=n;i++){
        minn[i]=0;
        shuang[i]=0;
        for(int j=i+1;j<=n;j++){
            shuang[j]=0;
            int t=max(i,pre[j]);
            minn[j]=minn[t]+1;
            if(j-t==1){
                shuang[i]=shuang[i-1];
                ans+=shuang[i];
            }
            else if(j-t==0){
                break;
            }
            else if(j-t==2){
                if(minn[i-2]==minn[i-1]){
                    if(shuang[i-2]||shuang[i-1]){
                        break;
                    }
                    else{
                        shuang[i]=1;
                        ans++;
                    }
                }
            }
            else{
                if(minn[t]==minn[t+1]&&minn[t+1]==minn[t+2]){
                    break;
                }
                if(minn[t]==minn[t+1]){
                    if(shuang[t]||shuang[t+1]){
                        break;
                    }
                    else{
                        shuang[i]=1;
                        ans++;
                    }
                }
                else if(minn[t+1]==minn[t+2]){
                    shuang[i]=shuang[t];
                    ans+=shuang[i];
                }
                else{
                    shuang[i]=shuang[t];
                    ans+=shuang[i];
                }
            }
        }
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
        solve();
    }
    return 0;
}
