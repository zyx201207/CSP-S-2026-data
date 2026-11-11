#include<bits/stdc++.h>
using namespace std;
int n,wh=0,j=1,n1=0,n2=0,i=1;
long long ans=0,sum=0,t1=0,t2=0;
int a[200005];
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>c[i];
        sum+=a[i];
    }
    for(long long x=0;x<sum/2;x+=a[i])wh++;
    for(i=1;i<=wh||j<=n-wh;i++)
    {
        t1+=a[i];
        t2+=a[n-j+1];
        n1=a[i];
        n2=a[n-j+1];
        if(t1>=t2)
        {
            for(j=j;t2<t1;j++)
            {
                t2+=a[n-j+1];
                if(c[i]!=c[n-j+1])ans+=a[n-j+1];
            }
        }
        else if(t1<=t2)
        {
            for(i=i;t1<t2;i++)
            {
                t1+=a[i];
                if(c[i]!=c[n-j+1])ans+=a[i];
            }
        }
    }
    cout<<ans;

    return 0;
}
