#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,x,i,j,ans;
    char y;
    cin>>n>>x>>y;
    a[1]=x;
    c[1]=y;
    for(i=2;i<=n;i++)
        cin>>a[i]>>c[i];
    i=1;
    j=n;
    ans=0;
    while(i<j)
    {
        if(a[i]>a[j])
        {
            a[i]=a[i]-a[j];
            if(c[i]!=c[j])
                ans=ans+a[j];
            j--;
        }
        else if(a[i]==a[j])
        {
            if(c[i]!=c[j])
                ans=ans+a[j];
            i++;
            j--;
        }
        else if(a[i]<a[j])
        {
            a[j]=a[j]-a[i];
            if(c[i]!=c[j])
                ans=ans+a[i];
            i++;
        }
    }
    cout<<ans;
    return 0;
}
