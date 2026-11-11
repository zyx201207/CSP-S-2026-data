#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum=0;
char t[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>t[i];
        sum+=a[i];
    }
    long long hed=1,tal=n,nw=a[n],ans=0;
    while(hed<tal)
    {
        if(t[hed]!=t[tal])
        {
            ans+=min(nw,a[hed]);
        }
        nw-=a[hed];
        if(nw<0)
        {
            while(nw+a[tal-1]<0)
            {
                tal--;
                nw+=a[tal];
                if(t[tal]!=t[hed])
                {
                    ans+=a[tal];
                }
            }
            tal--;
            nw+=a[tal];
            if(t[tal]!=t[hed])
            {
                ans+=(a[tal]-nw);
            }
        }
        hed++;
    }
    cout<<ans;
    return 0;
}
