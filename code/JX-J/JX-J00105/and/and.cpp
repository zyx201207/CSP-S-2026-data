#include<bits/stdc++.h>
using namespace std;
long long w[100000],a[100000],b[100000];//d y
long long ans=0;
long long m,n;
void h(long long k)
{
    for(int i=1;i<=n;i++)
    {
        if(b[i]==0&&i>=a[k-1])
        {
            b[i]=1;
            a[k]=i;
            if(k==m)
            {
                long long l;
                if(m>=3)
                {
                   l=w[a[1]]&w[a[2]];
                for(int q=3;q<=m;q++)
                {
                    l=l&w[a[q]];
                }
                }
                else
                {
                    if(m==1)l=w[a[1]];
                    if(m==2)l=w[a[1]]&w[a[2]];
                }
                ans=max(ans,l);

            }
            else
            {
                h(k+1);
            }
            b[i]=0;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
    }
    h(1);
    cout<<ans;
    return 0;
}
