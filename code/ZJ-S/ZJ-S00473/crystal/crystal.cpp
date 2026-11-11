#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll m,a[500005],p[500005],k;
int maxx=1,ans=0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    bool flag=0;
    for(int i=1;i<=n;i++)
    {
        int lls=1;
        for(int j=1;j<=n;j++)
        {
            if(a[i]>=a[j])
                p[lls++]=a[i]-a[j];
        }
        sort(p+1,p+lls);
        k=m;
        int l=2;
        ans=1;
        while(k>0&&l<lls)
        {
            if(k>=p[l])
            {
                k-=p[l];
                ans++;
            }
            else break;
            l++;
        }
        maxx=max(maxx,ans);
    }
    cout<<maxx;
    return 0;
}