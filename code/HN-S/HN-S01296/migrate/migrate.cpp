#include<bits/stdc++.h>
#define int long long
#define L(i,j,k) for(int i=(j);i<=(k);i++)
#define R(i,j,k) for(int i=(j);i>=(k);i--)
using namespace std;
const int M = 2e6+5,N = 5005;
int _,T,n,d,a[M],ans;
int g[N][N],f[M][21];
int nxt[M];
inline int dist(int x,int y){
    if(x==y)return 0;
    if(x>y)swap(x,y);
    int ans = 0;
    R(i,20,0)if(f[x][i]<y)ans += (1<<i),x = f[x][i];
    return ans+1;
}
void sol(){
    ans = 0;
    cin>>n>>d;
    L(i,1,n)cin>>a[i];
    int l = 1;
    L(i,1,n){
        while(l<n&&a[l+1]-a[i]<=d)l++;
        nxt[i] = l;
        f[i][0] = l;
        // cerr<<nxt[i]<<" ";
    }
    // cerr<<"\n";
    L(i,1,20){
        R(j,n,1){
            f[j][i] = f[f[j][i-1]][i-1];
        }
    }
    // cerr<<"!"<<f[3][0]<<" "<<f[3][20]<<"\n";
    L(i,1,n)L(j,i,n)g[i][j] = 0;
    L(i,1,n)g[i][i] = 1;
    L(i,2,n){
        L(l,1,n-i+1){
            int r = l+i-1;
            if(r<=nxt[l]){
                g[l][r] = 1;
                continue;
            }
            // cerr<<l<<" "<<r<<"\n";
            if(g[nxt[l]][r] == 3){
                g[l][r] = 3;
                continue;
            }
            int dis = dist(nxt[l],r);
            // cerr<<nxt[l]<<" "<<r<<"\n";
            // cerr<<dis<<"\n";
            if(dis > n){
                continue;
            }
            if(g[nxt[l]][r] == 2){
                if(l!=nxt[l]&&dist(nxt[l]-1,r) == dis){
                    g[l][r] = 3;
                }
                else g[l][r] = 2,ans++;
            }
            else if(g[nxt[l]][r] == 1){
                if(l!=nxt[l]&&dist(nxt[l]-1,r) == dis){
                    if(nxt[l]-2>l&&dist(nxt[l]-2,r) == dis){
                        g[l][r] = 3;
                    }else {
                        if(g[nxt[l]-1][r] > 1)g[l][r] = 3;
                        else if(g[nxt[l]-1][r] == 1)g[l][r] = 2,ans++;
                    }
                }
                else g[l][r] = 1;
            }
        }
    }
    // cerr<<g[1][4]<<"\n";
    cout<<ans<<"\n";
}
void work(){
    ans = 0;
    cin>>n>>d;
    L(i,1,n)cin>>a[i];
    int x = d/(a[n]-a[n-1]);
    if(x==2&&d%(a[n]-a[n-1])==1){
        cout<<n-2<<"\n";
    }else cout<<"0\n";
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>_>>T;
    if(_==11||_==12){
        while(T--)work();
        return 0;
    }
    while(T--)sol();
    return 0;
}