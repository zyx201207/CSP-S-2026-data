#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
#define fi first
#define se second
#define mp make_pair
#define debug1(x) cerr<<(#x)<<"="<<(x)<<" "
#define debug2(x) cerr<<(#x)<<"="<<(x)<<"\n"
template<class T>
inline void operator += (vector<T>&x,const T &y){x.emplace_back(y);}
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
int ld(int l,int r){return rnd()%(r-l+1)+l;}
namespace ARIS2_0{
    void solve(){
        int c=0,n=500,m=(5e5/20),d=20,q=1e5;
        cout<<c<<" "<<n<<" "<<m<<" "<<d<<" "<<q<<"\n";
        for(int i=1;i<=m;i++)cout<<(int)(1e9)<<" ";
        cout<<"\n";
        int l=1;
        for(int i=1;i<=n;i++){
            int k=(5e5/500);
            cout<<k<<" ";
            int r=l+k-1;
            for(int j=l;j<=r;j++){
                cout<<(j-1)%m+1<<" "<<ld(1e8,1e9)<<" ";
            }
            cout<<"\n";
            l=r;
        }
        for(int i=1;i<=q;i++){
            int x=ld(1,m),y=ld(1,m);
            while(x==y)y=ld(1,m);
            cout<<x<<" "<<y<<"\n";
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)ARIS2_0::solve();
}