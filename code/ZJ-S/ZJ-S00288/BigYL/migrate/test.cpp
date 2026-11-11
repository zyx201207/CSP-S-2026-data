#include<bits/stdc++.h>
using namespace std;
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
namespace ARIS2_0{
    constexpr int maxn=2e6+10;
    ll x[maxn];
    int n;ll d;
    int R[maxn];
    namespace SPA{
        bool g1[maxn],g2[maxn];
        int f[maxn];
        void solve(){
            g1[1]=1;
            g2[1]=0;
            f[1]=0;
            for(int i=2;i<=n;i++){
                f[i]=n+10;
                g1[i]=g2[i]=0;
            }
            ll ans=0;
            for(int len=1;len<n;len++){
                if(R[1]==1)continue;
                if(R[1]>=len)f[len]=1;
                else f[len]=f[len-R[1]+1]+1;

                if(R[1]>=len)g1[len]=1;
                else{
                    g1[len]=(g1[len-R[1]+1] and f[len-R[1]+2]>f[len-R[1]+1]);
                }

                if(R[1]>=len)g2[len]=0;
                else{
                    if(g2[len-R[1]+1]){
                        g2[len]=(f[len-R[1]+2]>f[len-R[1]+1]);
                    }
                    else if(g1[len-R[1]+1]){
                        g2[len]=(g1[len-R[1]+2] and f[len-R[1]+2]==f[len-R[1]+1] and f[len-R[1]+3]>f[len-R[1]+1]);
                    }
                    else g2[len]=0;
                }

                if(f[len]>=n)g1[len]=g2[len]=0;

                if(g2[len]){
                    ans+=n-len+1;
                    // debug1(l);debug2(r);
                }
            }
            cout<<ans<<"\n";
        }
    }
    bool g1[5010][5010],g2[5010][5010];
    int f[5010][5010];
    void solve(){
        cin>>n>>d;
        bool SP=1;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            if(i>=2)SP=SP and (x[i]-x[i-1]==x[2]-x[1]);
        }
        int z=1;
        for(int i=1;i<=n;i++){
            while(z<=n and x[z]-x[i]<=d)z++;
            z--;
            R[i]=z;
        }
        if(SP){
            SPA::solve();
            return;
        }
        for(int i=1;i<=n;i++){
            g1[i][i]=1;
            g2[i][i]=0;
            f[i][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                f[i][j]=n+10;
                g1[i][j]=g2[i][j]=0;
            }
        }
        int ans=0;
        for(int len=2;len<=n;len++){
            for(int l=1,r=len;r<=n;l++,r++){
                //f[l][r]
                if(R[l]==l)continue;
                if(R[l]>=r)f[l][r]=1;
                else f[l][r]=f[R[l]][r]+1;

                if(R[l]>=r)g1[l][r]=1;
                else{
                    g1[l][r]=(g1[R[l]][r] and f[R[l]-1][r]>f[R[l]][r]);
                }

                if(R[l]>=r)g2[l][r]=0;
                else{
                    if(g2[R[l]][r]){
                        g2[l][r]=(f[R[l]-1][r]>f[R[l]][r]);
                    }
                    else if(g1[R[l]][r]){
                        g2[l][r]=(g1[R[l]-1][r] and f[R[l]-1][r]==f[R[l]][r] and f[R[l]-2][r]>f[R[l]][r]);
                    }
                    else g2[l][r]=0;
                }

                if(f[l][r]>=n)g1[l][r]=g2[l][r]=0;

                if(g2[l][r]){
                    ans++;
                    // debug1(l);debug2(r);
                }
            }
        }
        cout<<ans<<"\n";
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,T=1;
    cin>>c>>T;
    while(T--)ARIS2_0::solve();
}