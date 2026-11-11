#include<bits/stdc++.h>
#define int long long
#define ll unsigned long long
#define off ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pi pair<int,int>
#define pii pair<int,pair<int,int> >
#define fi first
#define se second
using namespace std;
const int N=505;
const int M=505;
const int Q=100005;
int cnt[N][N],a[N][N],c,t,n,m,x[N],ans;
signed main()
{
    off;
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                a[i][j]=((abs(x[i]-x[j])<=m)?1:1000000000000000000);
                cnt[i][j]=((abs(x[i]-x[j])<=m)?1:0);
            }
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(a[i][k]+a[k][j]<a[i][j])
                    {
                        a[i][j]=a[i][k]+a[k][j];
                        cnt[i][j]=cnt[i][k]*cnt[k][j];
                    }
                    else if(a[i][k]+a[k][j]==a[i][j])
                    {
                        cnt[i][j]+=cnt[i][k]*cnt[k][j];
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                //cout<<cnt[i][j]<<' ';
                ans+=(cnt[i][j]==2);
            }
            //cout<<'\n';
        }
        cout<<ans/2<<'\n';
    }
    return 0;
}
//file memory long long
/*
0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
*/
