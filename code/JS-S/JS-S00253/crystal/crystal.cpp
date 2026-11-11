#include <bits/stdc++.h>
using namespace std;

long long n,m,mina=0x3f3f3f3f,ans=0,mans=0;
long long a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        mina=min(mina,a[i]);
    }
    sort(a+1,a+n+1);
    int mid=mina;
    while(mid-a[n]<=m)
    {
        int c=m;
        ans=0;
        for(int i=n;i>=1;i--)
        {
            if(mid-a[i]<0)
                continue;
            if(c-(mid-a[i])>=0)
            {
                ans++;
                c-=mid-a[i];
            }
            else
            {
                break;
            }
        }
        if(c!=0 && ans==n)
            ans--;
        mid+=1;
        mans=max(mans,ans);
    }
    cout << mans;
    return 0;
}
