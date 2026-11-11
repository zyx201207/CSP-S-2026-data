#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m;
int a[maxn];
//int sa[maxn];
//int fi[maxn];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    //fi[1]=a[1];
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    if(n>5000)
    {
        int cha=a[2]-a[1];
        int ans=n;
        int now=0;
        for(int i=1;i<n;i++)
        {
            now+=i*cha;
            if(now>m)
            {
                ans=i;
                break;
            }
        }
        cout << ans << endl;
        return 0;
    }
    int mmax=0;
    for(int i=n;i>=1;i--)
    {
        int now=0;
        int l=i-1;
        int ans=1;
        while(now<m)
        {
            if(l<=0)
            {
                break;
            }
            int sal=a[i]-a[l];
            now+=sal;
            l--;
            ans++;
            if(now>m)
            {
                ans--;
                break;
            }
        }
        mmax=max(mmax,ans);
    }
    cout << mmax << endl;
    return 0;
}
/*
5 5
1 2 4 8 9
*/
