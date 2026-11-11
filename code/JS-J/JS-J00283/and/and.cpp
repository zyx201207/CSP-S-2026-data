#include <bits/stdc++.h>
using namespace std;

int n,m;
long long a[200005][31];
long long maxa=0;
long long maxb=0;
long long aa[100005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i][0];
        long long a1=a[i][0];
        aa[i]=a1;
        if(maxa<=a1)
        {
            maxa=max(maxa,a1);
        }
        for(int j=1;j<=30;j++)
        {
            if(a1%2==1)
                a[i][j]=1;
            else
                a[i][j]=0;
            if(a==0)
                continue;
            a1/=2;
        }
    }
    sort(aa+1,aa+n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=30;j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    if(m==1)
    {
        cout << maxa;
        return 0;
    }
    if(m==n)
    {
        long long cnt=1;
        long long ans=0;
        for(int i=1;i<=30;i++)
        {
            bool flag=true;
            for(int j=1;j<=n;j++)
            {
                if(!flag)
                    break;
                if(a[j][i]!=1)
                    flag=false;
            }
            if(flag)
                ans+=cnt;
            cnt=cnt*2;
        }
        cout << ans;
        return 0;
    }
    if(m==2)
    {
        long long ans=0;
        for(int p=1;p<=n-1;p++)
        {
            for(int j=p;j<=n-1;j++)
            {
                long long ans1=0;
                long long cnt=1;
                for(int i=1;i<=30;i++)
                {
                    if(a[j][i]==1 && a[j+1][i]==1)
                        ans1+=cnt;
                    cnt=cnt*2;
                }

                ans=max(ans,ans1);
            }
        }
        cout << ans;
        return 0;
    }
    if(m==n-1)
    {
        long long cnt=1;
        long long ans=0;
        for(int p=1;p<=n;p++)
        {
            long long ans1=0;
            cnt=1;
            for(int i=1;i<=30;i++)
            {
                bool flag=true;
                for(int j=1;j<=n;j++)
                {
                    if(!flag)
                        break;
                    if(j==p)
                        continue;
                    if(a[j][i]!=1)
                        flag=false;
                }
                if(flag)
                    ans1+=cnt;
                cnt=cnt*2;
            }
            ans=max(ans,ans1);
        }
        cout << ans;
        return 0;
    }
    cout << aa[m];
    return 0;
}

