#include<bits/stdc++.h>
using namespace std;
int n;
char c[200005];
long long a[200005];
long long ans=0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    while(l<r)
    {
        if(a[l]<a[r])
        {
            if(c[l]!=c[r]) ans+=a[l];
            a[r]-=a[l];
            l++;
        } 
        else if(a[l]>a[r])
        {
            if(c[l]!=c[r]) ans+=a[r];
            a[l]-=a[r];
            r--;
        }
        else 
        {
            if(c[l]!=c[r]) ans+=a[l];
            l++,r--;
        }
    }
    cout<<ans;
    return 0;
}