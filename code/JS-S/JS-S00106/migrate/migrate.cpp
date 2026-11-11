#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
const int N=2e6+5;
int a[N];
int f[N];
int dp[N];
int g[N];
int ans=0;

signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--) {
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(c==11||c==12) {
            int D=a[2]-a[1];
            int k=d/D;
            if(k==0||k==1||n-2*k+1<=0) {
                printf("0\n");
                continue;
            }
            printf("%d\n",n-2*k+1);
            continue;
        }
        ans=0;
        for(int l=1;l<n;l++) {
            for(int r=l+1;r<=n;r++) {
                int maxx=0;
                for(int i=l;i<r;i++) {
                    maxx=max(maxx,a[i+1]-a[i]);
                }
                if(maxx>d) continue;
                int pos=l;
                int cnt=0;
                f[l]=0;
                for(int i=l+1;i<=r;i++) {
                    if(i==r||a[i+1]-a[pos]>d) {
                        pos=i;++cnt;
                        f[i]=cnt;
                        g[cnt]=i;
                    }
                    else f[i]=cnt+1;
                }
                g[0]=l;
                //cout<<l<<' '<<r<<' '<<cnt<<'\n';
                //cout<<66<<'\n';
                //for(int i=l;i<=r;i++) {

                //    cout<<f[i]<<' ';
                //}
                //cout<<'\n';
                dp[l-1]=0;
                dp[l]=1;
                for(int i=l+1;i<=r;i++) {
                    int R=g[f[i]-1];
                    int lx=l,ly=R,L=R+1;
                    while(lx<=ly) {
                        int mid=lx+ly>>1;
                        if(f[mid]==f[i]-1&&a[i]-a[mid]<=d) ly=mid-1,L=mid;
                        else lx=mid+1;
                    }
                    dp[i]=dp[R]-dp[L-1];
                    dp[i]+=dp[i-1];
                    //cout<<i<<' '<<L<<' '<<R<<' '<<dp[i]-dp[i-1]<<'\n';
                }
                if(dp[r]-dp[r-1]==2) ++ans;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


*/
