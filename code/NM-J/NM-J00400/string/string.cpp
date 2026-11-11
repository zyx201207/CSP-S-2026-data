#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
char c[200005];
long long ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    int l=1,r=n;
    while(l!=r)
    {
        long long s1=a[l],s2=a[r];
        char c1=c[l],c2=c[r];
        long long cnt=min(s1,s2);
        if(c1!=c2)
        {
            a[l]-=cnt;
            a[r]-=cnt;
            ans+=cnt;
        }
        else
        {
            a[l]-=cnt;
            a[r]-=cnt;
        }
        if(a[l]==0)l++;
        if(a[r]==0)r--;
    }
    cout<<ans;
    return 0;
}
