#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q;
const int N=5e5+1010;
const int M=5e5+1010;
ll z[N];
struct node{
    int v,w;
};
//vector<node> vec[N];
ll dp[1610][1610];
int sz;
void floyed(){
    for(int k=1;k<=sz;k++){
        for(int i=1;i<=sz;i++){
            for(int j=1;j<=sz;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
}
void solve1(){
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        if(k==1){
            int x1,d1;cin>>x1>>d1;continue;
        }
        //k==2
        int x1,d1,x2,d2;cin>>x1>>d1>>x2>>d2;
        ll tmp=d1+d2;
        dp[x1][x2]=min(dp[x1][x2],tmp);
        dp[x2][x1]=min(dp[x2][x1],tmp);
    }
    sz=m;
    floyed();
    for(int i=1;i<=q;i++){
        int l,r;cin>>l>>r;
        ll ans=z[l]+z[r]+dp[l][r];
        cout<<ans<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>z[i];
    }
    if(c==0||c<=8||(c>=7&&c<=11)){
        memset(dp,0x3f,sizeof(dp));
        for(int i=1;i<=m+n;i++){
            dp[i][i]=0;
        }
    }
    if(c==0||c>=7&&c<=11){
        solve1();
        return 0;
    }
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int v,d;cin>>v>>d;
            if(c==0||c<=8||1){
               dp[m+i][v]=dp[v][m+i]=d;
            }
            //vec[m+i].push_back({v,d});
            //vec[v].push_back({m+i,d});
        }
    }
    if(c==0||c<=8||1){
        sz=m+n;
        floyed();
        for(int i=1;i<=q;i++){
            int l,r;cin>>l>>r;
            ll ans=z[l]+z[r]+dp[l][r];
            cout<<ans<<'\n';
        }
    }
    return 0;
}
/*
0 3 7 20 2
 8 3 6 1 7 2 9
 3 1 4 2 5 5 100
 3 2 6 3 1 7 2
 4 3 2 5 100 4 6 6 7
 1 6
 2 3
*/
