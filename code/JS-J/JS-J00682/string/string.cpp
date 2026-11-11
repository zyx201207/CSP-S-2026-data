#include<bits/stdc++.h>
using namespace std;
long long ans,cnt;
const int N=2e5+100;
int a[N];
char c[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        cin>>c[i];
        cnt+=a[i];
    }
    if(cnt<=1e8)
    {
        string s;int h=0;
        for(int i=1;i<=n;i++)
        {
          int u=a[i];
          for(int j=1;j<=u;j++)
          {
              s[h]=c[i];
              h++;
          }
        }
       for(int i=0;i<h/2;i++)
        if(s[i]!=s[h-1-i]) ans++;
        cout<<ans;
    }
    else
    {
    long long g=cnt/2,l=a[1],r=a[n];
    long long l1=1,l2=n;
    while(l1<=l2)
    {
        if(l==r)
        {
            if(c[l1]!=c[l2])  ans+=a[l1];
             l1++;l2--;
            l+=a[l1];r+=a[l2];
        }
        else
        {
            if(l<r)
            {
                    if(c[l1]!=c[l2])
                    {
                        ans+=a[l1];
                        r-=a[l1];l=0;
                    }
                    l1++;
            }
            else
            {
                    if(c[l1]!=c[l2])
                    {
                        ans+=a[l2];
                        l-=a[l2];r=0;
                    }
                    l2--;
            }
        }
    }
    cout<<ans;
    }
    return 0;
}
