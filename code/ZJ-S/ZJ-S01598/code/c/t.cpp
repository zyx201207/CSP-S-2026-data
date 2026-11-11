#include<bits/stdc++.h>
#define rep(i, j, k) for(int i=(j); i<=(k); i++)
#define per(i, j, k) for(int i=(j); i>=(k); i--)
#define debug(a...) _debug(#a, a)
#define file(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std;
template<class T> void _debug(const char *s, T x){cout<<s<<'='<<x<<endl;}
template<class T, class... Nxt> void _debug(const char *s, T x, Nxt... nxt){
    int d=0;
    while(d||*s!=',') d+=*s=='(', d-=*s==')', cout<<*s++;
    cout<<'='<<x<<',';
    _debug(s+1, nxt...);
}
using ll=long long;
const int N=2e6+5;
int n, fa[N], pre[N], f[N][3], buc[N], cp[N], cs[N];
ll d, a[N], ans;

int get(int l, int r, int x){
    if(pre[r]<x || pre[l]>x) return 0;
    if(pre[r]==x) return cp[r];
    if(pre[l]==x) return cs[l];
    return buc[x];
}

void run(){
    rep(i, 1, n){
        f[i][0]=f[i][1]=f[i][2]=0;
        a[i]=fa[i]=pre[i]=buc[i]=cp[i]=cs[i]=0;
    }
    cin>>n>>d;
    rep(i, 1, n) cin>>a[i];
    for(int i=1, j=1; i<=n; i++){
        while(j<n && a[j+1]-a[i]<=d) j++;
        fa[i]=j;
    }
    for(int i=1, j=1; i<=n; i++){
        while(a[i]-a[j]>d) j++;
        pre[i]=j;
        buc[j]++;
    }
    rep(i, 1, n) cp[i]=pre[i]==pre[i-1]?cp[i-1]+1:1;
    per(i, n, 1) cs[i]=pre[i]==pre[i+1]?cs[i+1]+1:1;
    ans=0; 
    per(i, n-1, 1){
        memset(f[i], 0, sizeof(f[i]));
        int j=fa[i], k=fa[j];
        if(j==k) continue;
        if(i+1==j && j+1==k){
            f[i][0]=f[j][0];
            f[i][1]=f[j][1]+1;
        } else if(i+1==j){
            f[i][0]=f[j][0];
            f[i][1]=f[j][1]+(k-j);
        } else if(j+1==k){
            int c=j-max(i+1, pre[k])+1;
            if(c==2){
                f[i][0]=f[j][1]+1;
            } else if(c==1){
                f[i][0]=f[j][0];
                f[i][1]=f[j][1]+1;
                f[i][2]=f[j][0];
            }
        } else{
            int c=j-pre[k]+1, d=get(j+1, k, j-1);
            if(c==2){
                f[i][0]=f[j][1]+d;
            } else if(c==1){
                if(pre[k-1]==j){
                    f[i][0]=f[j][0]+d;
                    f[i][1]=f[j][1]+get(j+1, k, j);
                    f[i][2]=f[j][0];
                } else{
                    f[i][0]=f[j][2]+d;
                    f[i][1]=f[j][1]+1;
                    f[i][2]=f[j][2];
                }
            }
        }
        ans+=f[i][0];
    }
    cout<<ans<<'\n';
}

signed main(){
    file("migrate");
    cin.tie(0)->sync_with_stdio(0);
    int c, t;
    cin>>c>>t;
    rep(tc, 1, t){
        run();
    }
}