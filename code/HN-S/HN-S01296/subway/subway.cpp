#include<bits/stdc++.h>
#define int long long
#define L(i,j,k) for(int i=(j);i<=(k);i++)
#define R(i,j,k) for(int i=(j);i>=(k);i--)
#define vi vector<int>
#define ek emplace_back
using namespace std;
const int N = 505,M = 5e5+5,inf = 1e15;
int n,m,_,d,q,x,y,mn;
int a[M],k;
int f[N][N];
vi b[M],c[M];
inline void chkmn(int &x,int y){x = (x>y?y:x);}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>_>>n>>m>>d>>q;
    L(i,1,n){
        L(j,1,n){
            f[i][j] = inf;
        }
    }
    L(i,1,n)f[i][i] = 0;
    L(i,1,m)cin>>a[i];
    L(i,1,n){
        cin>>k;
        L(j,1,k){
            // cin>>b[j]>>c[j];
            cin>>x>>y;
            b[x].ek(i),c[x].ek(y);
        }
        // L(j,1,k){
        //     L(t,j+1,k){
        //         // cerr<<b[j]<<" "<<b[t]<<"\n";
        //         chkmn(f[b[j]][b[t]],c[j] + c[t]);
        //         chkmn(f[b[t]][b[j]],c[j] + c[t]);
        //     }
        // }
    }
    // cerr<<f[1][3]<<"\n";
    L(i,1,m){
        k = b[i].size()-1;
        L(j,0,k){
            L(t,j+1,k){
                chkmn(f[b[i][j]][b[i][t]],c[i][j] + c[i][t]);
                chkmn(f[b[i][t]][b[i][j]],c[i][j] + c[i][t]);
            }
        }
    }
    // cerr<<f[1][2]<<"\n";
    L(i,1,n){
        L(j,1,n){
            L(k,1,n){
                chkmn(f[j][k],f[j][i] + f[i][k]);
            }
        }
    }
    // cerr<<f[1][2]<<"\n\n";
    // int cnt = 0;
    L(i,1,q){
        cin>>x>>y;
        // cerr<<f[x][y]<<"\n";
        mn = inf;
        int k1 = b[x].size()-1,k2 = b[y].size()-1;
        L(j,0,k1){
            L(k,0,k2){
                chkmn(mn,c[x][j] + c[y][k] + f[b[x][j]][b[y][k]]);
                // cnt++;
            }
        }
        // cerr<<mn<<"\n";
        cout<<a[x]+a[y]+mn<<"\n";
    }
    // cerr<<cnt;
    return 0;
}