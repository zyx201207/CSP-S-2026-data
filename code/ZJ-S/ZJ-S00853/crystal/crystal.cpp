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
const int N=5e5+10,inf=2e18;
namespace D1n0{
    int n,a[N],m;
    inline void _(){
        n=r();m=r();
        for(int i=1;i<=n;++i)a[i]=r();
        sort(a+1,a+1+n);
        int ans=0;
        for(int i=1,j=1,S=0;i<=n;++i){
            S+=a[i];
            while(S+m<a[i]*(i-j+1)){
                S-=a[j++];
            }
            ans=max(ans,i-j+1);
        }
        wln(ans);
    }
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    D1n0::_();
}
/*
g++ crystal.cpp -o crystal -O2 -std=c++14
*/