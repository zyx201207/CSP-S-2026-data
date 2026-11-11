#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define fi first
#define se second
#define pb push_back
#define v(x) vector<x>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const ll inf=0x3f3f3f3f3f3f3f3f;
const int N=5010;
ll read(){
    ll x=0;
    bool f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=0;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return f?x:-x;
}
int ID,T,n;
ll x[N],d;
pii f[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ID=read(),T=read();
    while(T--){
        n=read(),d=read();
        for(int i=1;i<=n;i++){
            x[i]=read();
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int l=i;
            f[i]={0,1};
            for(int j=i+1;j<=n;j++){
                while(x[l]<x[j]-d) l++;
                if(l==j) break;
                f[j]={f[l].fi+1,0};
                for(int k=l;k<j&&f[k].fi==f[l].fi;k++){
                    f[j].se=(f[j].se+f[k].se);
                    if(f[j].se>2) f[j].se=3;
                }
                if(f[j].se==2) {
                    ans++;
                    // cout<<i<<" "<<j<<"\n";
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}