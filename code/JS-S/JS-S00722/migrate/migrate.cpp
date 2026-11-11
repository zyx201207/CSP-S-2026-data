#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+5;
int f[N],g[N],cnt1[N],cnt2[N];
ll x[N],sum[N],sum2[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n;
        ll d;
        cin>>n>>d;
        for(int i=0;i<n;++i)cin>>x[i],cnt1[i]=0,cnt2[i]=0;
        for(int i=0,j=0;i<n;++i){
            while(x[i]-x[j]>d)++j;
            f[i]=j;
            if(i!=j)++cnt1[j];
        }
        for(int i=n-1,j=n-1;i>=0;--i){
            while(x[j]-x[i]>d)--j;
            g[i]=j;
            if(i!=j)++cnt2[j];
        }
        ll ans=0;
        ll x=0;
        for(int i=0;i<n;++i)sum[i]=cnt2[i],sum2[i]=cnt1[i];
        for(int i=0;i<n;++i)if(g[i]!=i&&f[g[i]]==i)sum[g[i]]+=sum[i];
        for(int i=n-1;i>=0;--i)if(f[i]!=i&&g[f[i]]==i)sum2[f[i]]+=sum2[i];
        for(int i=0;i<n;++i){
            if(g[i]!=i&&f[g[i]]==i-1){
                ll ans1=cnt2[i];
                if(f[i-1]==f[i]){
                    ans1=sum[i];

                }
                ll ans2=sum2[g[i]];
                ans+=ans1*ans2;
            }
        }

        for(int i=0;i<n;++i){

            if(f[i]<i-1)
                if(f[f[i]]==f[f[i]+1])ans+=sum[f[i]+1];
                else ans+=cnt2[f[i]+1];
        }
        cout<<ans<<'\n';
    }
}
