#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005][35],power[35],x[200005],cnt[35],pos=0;
int flag[200005];
bool cmp[200005];
void f(int x)
{
    if(cnt[x]<m) return;
    for(int i=1;i<=n;i++)
    {
        if(cmp[i]==1)
        {
            continue;
        }
        if(a[i][x]==0)
        {
            cmp[i]=1;
            flag[++pos]=i;
        }
    }
    return;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    power[0]=1;
    for(int i=1;i<=31;i++)
    {
        power[i]=power[i-1]*2;
    }
    for(int i=1;i<=n;i++)
    {
        cin >> x[i];
        int temp=x[i];
        for(int j=30;j>=0&&x>0;j--)
        {
            if(temp>=power[j])
            {
                a[i][j]=1;
                cnt[j]++;
                temp-=power[j];
            }
        }
    }
    for(int i=30;i>=0;i--)
    {
        f(i);
        for(int j=1;j<=pos;j++)
        {
            for(int k=0;k<=30;k++)
            {
                cnt[k]-=a[flag[j]][k];
            }
        }
        for(int i=1;i<=n;i++) flag[i]=0;
    }
    long long ans=0;
    for(int i=30;i>=0;i--)
    {
        if(cnt[i]>=m) ans+=power[i];
    }
    cout << ans;
    return 0;
}
