
#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[(int)1e6+10];
long long g[(int)1e6+10][3];
long long len,x,y,sum,ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    a[0]=-1e13;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        if (a[i]==a[i-1])
        {
            g[len][1]++;
        }
        else
        {
            len++;
            g[len][1]=1;
            g[len][0]=a[i]-a[i-1];
            g[len][2]=g[len][0]+g[len-1][2];
        }
    }
    if(len>80000)

    {
        cout << min((long long)sqrt(2.0*m/g[100][0]),len);
        return 0;
    }
    for (int i=1;i<=len;i++)
    {
        x=0;
        sum=0;
        y=0;
        for (int j=i;j>=1;j--)
        {
            sum+=g[j][1]*(g[i][2]-g[j][2]);
            if (sum>m)
            {
                y=j;
                sum-=g[j][1]*(g[i][2]-g[j][2]);
                break;
            }
            x+=g[j][1];
        }
        if (sum<m)
        {
            x+=(m-sum)/(g[i][2]-g[y][2]);
        }
        ans=max(ans,x);
    }
    cout << ans;
}
