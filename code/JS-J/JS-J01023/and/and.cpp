#include <bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int n,m,kp,ans,a[N],vis[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;kp=n;
    for(int i=1,x;i<=n;i++) cin>>a[i];
    for(int i=29;~i&&kp>=m;i--){
        int cc=0;
        for(int j=1;j<=n;j++) if(!vis[j]&&(a[j]&(1<<i))) cc++;
        if(cc<m) continue;
        ans+=(1<<i);
        for(int j=1;j<=n;j++) if(!vis[j]&&!(a[j]&(1<<i))) vis[j]=1,kp--;
    }
    cout<<ans<<"\n";
}
/*

//freopen("and.in","r","stdin");
//freopen("and.out","w","stdout"); ...

Wish I get 100+100+?+? pts in the afternoon.

while(1):

    RRRR  PPPP
    R  R  P   P
    RRRR  PPPP    +     +
    R R   P     +++++ +++++
    R  R  P       +     +
    R   R P
*/
