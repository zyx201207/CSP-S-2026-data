#include<bits/stdc++.h>
using namespace std;

int a[200005];
char b[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;

    long long h=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        h+=a[i];
    }
    long long ans=0;
    for(int i=1,j=n;i<j;i++)
    {
        long long g=a[j];
        while(g<a[i])
        {
            if(b[j]!=b[i])
                ans+=a[j];
            j--;
            g+=a[j];
        }
        if(i==j)
        {
            //ans+=a[j];
            break;
        }
        if(g==a[i])
        {
            if(b[j]!=b[i])
                ans+=a[j];
            j--;
            continue;
        }
        if(b[i]!=b[j])
            ans+=a[j]-(g-a[i]);
        a[j]=g-a[i];
    }
    cout<<ans;
    return 0;
}

