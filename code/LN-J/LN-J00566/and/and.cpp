#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[20005];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long ans;
    long long maxx;
    long long maxand=-1;
    cin>>a[1];
    ans=a[1];
    maxx=a[1];
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
        ans&=a[i];
        if(a[i]>maxx)maxx=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if((a[i]&a[j])>maxand)maxand=a[i]&a[j];
        }
    }
    if(m==n)cout<<ans<<endl;
    else if(m==1)cout<<maxx<<endl;
    else if(m==2)cout<<maxand<<endl;
    else cout<<0<<endl;
    return 0;
}