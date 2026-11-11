#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e5+3;
int n;
char s[MAXN];
ll a[MAXN];
ll ans=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>s[i];
    }
    int l=1,r=n;
    while(l<=r)
    {
        if(s[l]==s[r])
        {
            if(a[l]>a[r])
            {
                a[l]-=a[r];
                r--;
            }
            else if(a[l]<a[r])
            {
                a[r]-=a[l];
                l++;
            }
            else
            {
                r--;
                l++;
            }
        }
        else
        {
            if(a[l]>a[r])
            {
                ans+=a[r];
                a[l]-=a[r];
                r--;
            }
            else if(a[l]<a[r])
            {
                ans+=a[l];
                a[r]-=a[l];
                l++;
            }
            else{
                ans+=a[l];
                l++;r--;
            }
        }
    }
    cout<<ans;
    return 0;
}
