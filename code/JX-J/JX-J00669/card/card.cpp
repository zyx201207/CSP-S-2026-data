#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(i) i<<1
#define rs(i) i<<1|1
#define lowbit(x) x&-x
const int N=5e5+10;
const int M=5e5+10;
const int base=1e9+7;
const int base1=1e9+9;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int n,m;
int a[N];
int cnt[N];
int b[N];
int tp;
int vis[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=5e2+10){
        for(int i=1;i<=n;i++){
            tp=0;
            for(int j=i;j<=n;j++){
                for(int k=1;k<=tp;k++){
                    if(b[k]==a[j]){
                        tp=k-1;
                        break;
                    }
                }
                b[++tp]=a[j];
            }
            for(int j=1;j<=tp;j++){
                cnt[b[j]]++;
            }
            for(int j=0;j<=m;j++){
                vis[j]=0;
            }
        }
    }else{
        for(int i=1;i<=n;i++){
            tp=0;
            for(int j=0;j<=m;j++){
                vis[j]=INF;
            }
            for(int j=i;j<=n;j++){
                if(vis[a[j]]==INF){
                    b[++tp]=a[j];
                    vis[a[j]]=tp;
                }else{
                    tp=vis[a[j]];
                    b[tp]==a[j];
                }
                //for(int k=1;k<=tp;k++){
                  //  if(b[k]==a[j]){
                    //    tp=k-1;
                      //  break;
                    //}
            }
            for(int j=1;j<=tp;j++){
                cnt[b[j]]++;
            }
        }
    }
    for(int i=1;i<m;i++){
        cout<<cnt[i]<<' ';
    }
    cout<<cnt[m];
    return 0;
}
/*

*/
