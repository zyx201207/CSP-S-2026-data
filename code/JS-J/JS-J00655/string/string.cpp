#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+10;
int n;
int a[MAXN];
char ch[MAXN];
int ans=0;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>ch[i];
    }
    ans=0;
    int l=1,r=n;
    while(l<=r)
    {
        if(a[l]<=a[r])
        {
            if(ch[l]!=ch[r])
            {
                ans+=a[l];
            }
            a[r]-=a[l];
            l++;
        }
        else
        {
            if(ch[l]!=ch[r])
            {
                ans+=a[r];
            }
            a[l]-=a[r];
            r--;
        }
    }
    cout<<ans;
    return 0;
}