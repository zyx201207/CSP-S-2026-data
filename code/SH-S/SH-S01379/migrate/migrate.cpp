#include<bits/stdc++.h>
#define int long long
using namespace std;
ifstream fin("migrate.in");
ofstream fout("migrate.out");
#define cin fin
#define cout fout
const int N=2e6+5;
int C,T,n,d,x[N],l[N],r[N],dp[N][3],ans;
signed main() {
    // auto st=clock();
    // ios::sync_with_stdio(0);
    cin>>C>>T;
    while(T--) {
        cin>>n>>d; ans=0;
        for(int i=1;i<=n;i++)
            dp[i][0]=dp[i][1]=dp[i][2]=0;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1,j=1;i<=n;l[i]=j,i++) {
            while(x[i]-x[j]>d) j++;
        }
        for(int i=n,j=n;i>=1;r[i]=j,i--) {
            while(x[j]-x[i]>d) j--;
        }
        for(int i=n;i>=1;i--) {
            if(i<n) {
                int R=r[i],l1=l[R],l2=l[R-1];
                if(l1==i) dp[i][0]+=dp[R][0],dp[i][2]+=dp[R][2];
                if(l1==i-1) dp[i][1]+=dp[R][0];
                if(l2==i) dp[i][2]+=dp[R][1];
                dp[i][0]+=R-max(i,r[i-1]);
                if(r[i-1]>i) dp[i][1]+=r[i-1]-max(i,i>1?r[i-2]:0);
                ans+=dp[R][1]+dp[R][2];
            }
        }
        cout<<ans<<'\n';
    }
    // auto ed=clock();
    // cerr<<fixed<<setprecision(3)<<1000.0*(ed-st)/CLOCKS_PER_SEC<<" ms\n";
}