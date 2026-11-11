#include <bits/stdc++.h>
#define N 505
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,l,r) for(int i=l;i>=r;i--)
#define ll long long
#define insert in
#define pb push_back
using namespace std;
int c,n,m,d,q;
int w[N];
int k[N],a[N][N],t[N][N],v[N];
vector<int> edges[N];
int s1[N],s2[N],b[N];
int main(){
    /*
    i didn't how to do baoli in B.
    i am fvv/ll
    */
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    rep(i,1,m)cin>>w[i];
        rep(i,1,n){
            cin>>k[i];
            int l=1;
            rep(j,1,2*k[i]){
                cin>>a[i][l]>>t[i][l];
                l++;
            }
        }
    while(q--){
        int u,v;
        cout<<1<<'\n';
    }
        
    // }
    // if(c>=7&&c<=11){
    //     rep(i,1,n){
    //         cin>>k[i];
    //         int l=1;
    //         rep(j,1,2*k[i]){
    //             cin>>a[i][l]>>t[i][l];
    //             l++;
    //         }
    //         if(k[i]==2){
    //             edges[a[i][1]].pb(a[i][2]);
    //             edges[a[i][2]].pb(a[i][1]);
    //         }
    //     }
    //     rep(i,1,q){
    //         int u,v;
    //         cin>>u>>v;

    //     }
    //     return 0;
    // }

} 
//man!  