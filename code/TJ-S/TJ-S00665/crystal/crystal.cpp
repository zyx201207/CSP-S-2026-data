#include <cstdio>
#include <algorithm>

template <typename T> bool tense(T &a,const T &b){return a>b?a=b,true:false;}
template <typename T> bool relax(T &a,const T &b){return a<b?a=b,true:false;}

namespace Solve{
    const int MAXN=5e5+5;
    int n;long long m;
    long long a[MAXN];
    namespace Force{
        int ans=0;
        void dfs(int x){
            if(x>m){
                for(int i=1;i<n;i++){
                    int t=0;
                    for(int j=1;j<i;j++) if(a[i]==a[j]) t++;
                    relax(ans,t);
                }
                return;
            }
            for(int i=1;i<=n;i++){
                a[i]++;
                dfs(x+1);
                a[i]--;
            }
        }
        void solve(){
            dfs(1);
            printf("%d\n",ans);
        }
    }
    namespace Better{
        int d[MAXN],s[MAXN];
        bool check(int mid,int x){
            int sum=0;
            for(int i=mid;i<x;i++) sum+=s[i]-s[x];
            return sum<=m;
        }
        void solve(){
            a[0]=0;
            for(int i=1;i<n;i++) d[i]=a[i+1]-a[i];
            for(int i=n;i>=1;i--) s[i]=s[i+1]+d[i];
            // for(int i=1;i<=n;i++) printf("%d%c",d[i]," \n"[i==n]);
            // for(int i=1;i<=n;i++) printf("%d%c",s[i]," \n"[i==n]);
            int ans;
            for(int i=1;i<=n;i++){
                int l=1,r=i-1,res=-1;
                while(l<=r){
                    int mid=(l+r)>>1;
                    if(check(mid,i)) r=mid-1,res=mid;
                    else l=mid+1;
                }
                if(res!=-1) relax(ans,i-res+1);
            }
            printf("%d\n",ans);
        }
    }
    namespace Std{
        long long d[MAXN],s[MAXN],ss[MAXN];
        bool check(int mid,int x){
            int sum=0;
            // for(int i=mid;i<x;i++) sum+=s[i]-s[x];
            sum=ss[x-1]-ss[mid-1]-s[x]*(x-1ll-mid+1);
            return sum<=m;
        }
        void solve(){
            for(int i=0;i<=n+1;i++) ss[i]=s[i]=d[i]=0;

            for(int i=1;i<n;i++) d[i]=a[i+1]-a[i];
            for(int i=n;i>=1;i--) s[i]=s[i+1]+d[i];
            for(int i=1;i<=n;i++) ss[i]=ss[i-1]+s[i];
            // for(int i=1;i<=n;i++) printf("%d%c",d[i]," \n"[i==n]);
            // for(int i=1;i<=n;i++) printf("%d%c",s[i]," \n"[i==n]);
            int ans=1;
            for(int i=1;i<=n;i++){
                int l=1,r=i-1,res=-1;
                while(l<=r){
                    int mid=(l+r)>>1;
                    if(check(mid,i)) r=mid-1,res=mid;
                    else l=mid+1;
                }
                if(res!=-1) relax(ans,i-res+1);
            }
            printf("%d\n",ans);
        }
    }
    void solve(){
        scanf("%d%lld",&n,&m);

        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        std::sort(a+1,a+n+1);
        // for(int i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
        // Force::solve();
        // Better::solve();
        Std::solve();
    }
}

int main(){
    freopen("crystal.in","r",stdin);
    // freopen("crystal1.in","r",stdin);
    freopen("crystal.out","w",stdout);

    Solve::solve();

    return 0;
}