#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
#define mp mack_pair
#define pb emplace_back
using namespace std;
namespace IO{
    inline int r(){
        int x=1,y=0;
        char c=getchar();
        while(c<'0'||c>'9'){
            if(c=='-')x=-1;c=getchar();
        }
        while(c>='0'&&c<='9'){
            y=(y<<1)+(y<<3)+(c^48);c=getchar();
        }
        return x*y;
    }
    inline void wi(int x){
        if(!x)return;
        if(x<0){putchar('-');x=-x;}
        wi(x/10);putchar(48^(x%10));
    }
    inline void ww(int x){if(!x)putchar('0');else wi(x);putchar(' ');}
    inline void wln(int x){if(!x)putchar('0');else wi(x);putchar('\n');}
    inline void w(int x){if(!x)putchar('0');else wi(x);}
}
using namespace IO;
const int N=2e6+10,M=505,inf=4e18;
namespace D1n0{
    int n,d,a[N],fir[N],f1[N],f2[N];
    inline void solve(){
        n=r();d=r();
        for(int i=1;i<=n;++i)a[i]=r();
        int ans=0;
        for(int i=1,j=1;i<=n;++i){
            while(a[i]-a[j]>d)++j;
            fir[i]=j;
        }
        fir[n+1]=n+1;
        for(int i=1;i<=n;++i){
            f1[i]=f2[i]=0;
            int j=fir[i];
            f1[i]=fir[i+1]-fir[i];
            if(j<=i-2){
                if(fir[i+1]>j+1)f2[i]=fir[j+2]-fir[j+1];
                else ans+=fir[j+2]-fir[j+1];
            };
            if(j!=i&&fir[i+1]!=fir[i])f1[i]+=f1[j],f2[i]+=f2[j];
            else ans+=f2[j];//ww(ans+f2[i]);
            if(j<=i-2&&fir[j]==fir[j+1]&&fir[j]!=fir[j+2]){
                //ww(fir[j]);
                if(fir[i+1]>j+1)f2[i]+=f1[fir[j]];
                else ans+=f1[fir[j]];
            }
            ans+=f2[i];//wln(ans);
        }
        wln(ans);
    }
    inline void _(){
        int c=r(),t=r();
        while(t--)solve();
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    D1n0::_();
}
/*
g++ migrate.cpp -o migrate -O2 -std=c++14
*/