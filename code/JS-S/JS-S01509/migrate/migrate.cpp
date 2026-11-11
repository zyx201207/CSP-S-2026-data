#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int n,d,dp[N],a[N],l[N],an[N],ans;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int C,T;
    cin>>C>>T;
    while(T--)
    {
        cin>>n>>d;ans=0;
        for(int i=1;i<=n;i++) cin>>a[i],dp[i]=0,l[i]=i,an[i]=0;
        int pos=1;
        for(int i=2;i<=n;i++)
        {
            while(pos<i&&a[i]-a[pos]>d) pos++;
            l[i]=pos;
        }
        for(int i=2;i<n;i++)
        {
            if(l[i]==l[i+1]||l[i]==i) continue;
            dp[i]=l[i+1]-l[i]+dp[l[i]];
        }
        for(int i=2;i<=n;i++)
        {
            if(l[i]==i) continue;
            if(l[i]==i-1) {ans+=an[i-1],an[i]=an[i-1];continue;}
            if(l[l[i]]==l[i]) continue;
            if(l[l[i]+1]==l[i])
            {
                an[i]=an[l[i]];
                ans+=an[i];
                continue;
            }
            int ll=l[l[i]+1],rr=l[l[i]+2]-1;
            if(ll>rr)
            {
                if(ll==l[l[i]]) an[i]=0;
                else an[i]=an[l[l[i]]];
                ans+=an[i];continue;
            }
            if(ll==l[l[i]]) an[i]=rr-ll+1+dp[ll];
            else
            {
                if(ll-1==l[l[i]])
                {
                    if(l[ll-1]==l[l[l[i]]]) an[i]=rr-ll+1;
                    else an[i]=rr-ll+1+an[l[l[i]]];
                }else{
                    int poss=l[l[i]];
                    if(l[poss]==l[poss-1])
                    {
                        if(l[poss-1]==l[poss-2]) an[i]=rr-ll+1;
                        else an[i]=rr-ll+2+dp[poss];
                    }else an[i]=rr-ll+1+an[poss];
                }
            }
            ans+=an[i];
        }
        cout<<ans<<'\n';
    }
}
