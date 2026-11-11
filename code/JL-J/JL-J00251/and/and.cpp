#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000010];
long long ans=0;
bool was;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.in","r",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j<=n;j++)
            {
                if(ans<a[i]&a[j])
                {
                    ans=a[i];
                }
            }
        }
    }
    if(m==3)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {

                for(int ya=j+1-i;ya++)
                {
                    ans=m;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
