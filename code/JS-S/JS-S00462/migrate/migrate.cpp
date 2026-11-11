#include<bits/stdc++.h>
using namespace std;

int C,T;
int n;
long long d;
long long ans;
long long a[2000009];
int dp[2000009][2];
int nxt[2000009];
int las[2000009];

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>C>>T;
    while(T--)
    {
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            dp[i][0]=dp[i][1]=0;
        }
        for(int l=1,r=1;l<=n;l++)
        {
            r=max(l,r);
            while(r<n&&a[r+1]-a[l]<=d)r++;
            nxt[l]=r;
        }
        for(int l=n,r=n;r>0;r--)
        {
            l=min(l,r);
            while(l>1&&a[r]-a[l-1]<=d)l--;
            las[r]=l;
        }
        for(int i=1;i<=n;i++)
        {
            dp[i][1]=dp[las[i]][1]+(las[i]+1>=i?0:dp[las[i]+1][0]-1);

            dp[i][0]++;

            if(nxt[i]!=i&&las[nxt[i]]==i)dp[nxt[i]][0]+=dp[i][0];
            ans+=dp[i][1];
            //cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
        }

        cout<<ans<<"\n";
    }

    return 0;
}
