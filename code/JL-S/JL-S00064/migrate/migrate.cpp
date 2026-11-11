#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define mem(a,b) memset(a,b,sizeof(a));
#define all(x) (x).begin(),(x).end()
#define abs_(x) ((x)<0?-(x):(x))
#define sz(x) ((int)(x).size())
#define ull unsigned long long
#define pb push_back
#define fi first
#define se second
using namespace std;
int c,T;
int n,d;
bool vis[2000005];
int a[2000005];
// int nxt[2000005];
// int pre[2000005];
bool flag[305][305];
// vector<int>mp[2000005];
// void dfs(int u,int t){
//     if(u==t){f[u]=1;return;}
//     if(vis[u]) return;

// }
// void solve(){

// }
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--){
        int ans=0;
        cin>>n>>d;
        rep(i,1,n) cin>>a[i];
        // rep(i,1,n){
        //     rep(j,i+1,n){
        //         if(abs_(a[i]-a[j])<=d) mp[i].pb(j),mp[j].pb(i);
        //     }
        // }
        // rep(i,1,n){
        //     rep(j,i+1,n){
        //         if(abs_(a[j]-a[i])<=d) nxt[i]=j,pre[j]=i;
        //     }
        // }
        rep(i,1,n){
            rep(j,i+1,n){
                // if(i==j) continue;
                int id=i;
                int cnt=0;
                rep(_,1,n){
                    rep(__,1,n){
                        flag[_][__]=1;
                    }
                }
                while(abs_(a[j]-a[id])>d){
                    int nxt=id;
                    rep(k,id,j){
                        if(abs_(a[id]-a[k])<=d&&flag[id][k]) nxt=k;
                    }
                    if(id==nxt){cnt=-1;break;}
                    flag[id][nxt]=flag[nxt][id]=0;
                    id=nxt;
                    cnt++;
                }
                if(cnt==-1) continue;
                if(id!=j){
                    int flagg=0;
                    rep(k,id+1,j-1){
                        flagg|=(flag[id][k]&flag[k+1][j]);
                        if(flagg){
                            flag[id][k]=flag[k+1][j]=0;
                            break;
                        }
                    }
                    if(!flagg) cnt=-9191;
                    else cnt++;
                }
                int cnt1=cnt;
                // rep(_,1,n){
                //     rep(__,1,n){
                //         cout<<flag[i][j];
                //     }
                //     cout<<"\n";
                // }
                id=j;
                cnt=0;
                while(abs_(a[i]-a[id])>d){
                    int pre=id;
                    per(k,id,i){
                        if(abs_(a[id]-a[k])<=d&&flag[id][k]) pre=k;
                    }
                    if(id==pre){cnt=-1;break;}
                    flag[id][pre]=flag[pre][id]=0;
                    id=pre;
                    cnt++;
                }
                if(cnt==-1) continue;
                if(id!=i){
                    int flagg=0;
                    rep(k,i+1,id-1){
                        flagg|=(flag[i][k]&flag[k+1][id]);
                        if(flagg){
                            flag[i][k]=flag[k+1][id]=0;
                            break;
                        }
                    }
                    if(!flagg) cnt=-7878;
                    else cnt++;
                }
                ans+=(cnt1==cnt);
                // solve(i,j);
                // rep(_,1,n){
                //     rep(__,1,n){
                //         cout<<flag[i][j];
                //     }
                //     cout<<"\n";
                // }
                // cout<<i<<' '<<j<<' '<<cnt1<<' '<<cnt<<"\n";
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/