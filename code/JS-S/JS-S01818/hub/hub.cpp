#include<bits/stdc++.h>
#define int long long
#define r(x) x=read()
#define w(x) write(x)
#define sp putchar(' ')
#define en putchar('\n')
using namespace std;
int read(){int x=0,f=1;char ch=getchar();while(!isdigit(ch)) f=(ch=='-'?-f:f),ch=getchar();while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();return x*f;}
void write(int x){if(x<0) x=-x,putchar('-');if(x>9) write(x/10);putchar(x%10^48);}
const int N=1e6+10;
vector<int> G[N];
void solve(){
    int r(n),r(k);
    for(int i=1;i<=n;i++) G[i].clear();
    for(int i=1;i<n;i++){
        int r(u),r(v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(n==k) w(0),en;
    else if(k==n-1){
        w(1),en;
    }else{
        w((n-k)/2),en;
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int r(c),r(t);while(t--) solve();
    return 0;
}
